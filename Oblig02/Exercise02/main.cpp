#include <iostream>

#include <thread>
#include <atomic>
#include <vector>
#include <algorithm>
#include <mutex>
#include <condition_variable>

using namespace std;

int main() {

    bool stop = false;
    int account = 0;
    mutex m;
    condition_variable cond;

    int clients = 50;
    int banks = 50;

    vector<std::thread> client;
    vector<std::thread> bank;

    for (int i = 0; i < banks; i++)
        bank.emplace_back(
                [&] {
                    while (!stop) {
                        std::unique_lock<std::mutex> mlock(m);
                        cout << "bank:   " << this_thread::get_id() << " account: " << account << "\t\t";
                        int rand = (std::rand() % 50) + 1;
                        while (account - rand <= 0)
                            cond.wait(mlock);

                        account -= rand;
                        cout << "bank:   " << this_thread::get_id() << " account_update: " << account << endl;
                    }
                }
        );

    for (int i = 0; i < clients; i++)
        client.emplace_back(
                [&] {
                    while (!stop) {
                        std::unique_lock<std::mutex> mlock(m);
                        cout << "thread: " << this_thread::get_id() << " account: " << account << "\t\t";
                        int rand = (std::rand() % 50) + 1;
                        account += rand;
                        cout << "thread: " << this_thread::get_id() << " account_update: " << account << endl;
                        mlock.unlock();
                        cond.notify_one();
                    }
                }
        );

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    stop = true;


    std::for_each(bank.begin(), bank.end(), [](std::thread &t) { t.join(); });
    std::for_each(client.begin(), client.end(), [](std::thread &t) { t.join(); });

    return 0;
}