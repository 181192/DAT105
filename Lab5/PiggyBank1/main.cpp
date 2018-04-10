#include <iostream>

#include <thread>
#include <atomic>
#include <vector>
#include <algorithm>
#include <mutex>

using namespace std;

int main() {

    bool stop = false;
    int account = 0;
    mutex m;

    int clients = 50;
    int banks = 1;

    vector<std::thread> client;
    vector<std::thread> bank;

    for (int i = 0; i < banks; i++)
        bank.emplace_back(
                [&] {
                    while (!stop) {
                        m.lock();
                        int rand = (std::rand() % 50) + 1;
                        if (account - rand >= 0)
                            account -= rand;
                        m.unlock();
                    }
                }
        );

    for (int i = 0; i < clients; i++)
        client.emplace_back(
                [&] {
                    while (!stop) {
                        m.lock();
                        cout << "thread: " << i << " account: " << account << "\t\t";
                        int rand = (std::rand() % 50) + 1;
                        account += rand;
                        cout << "thread: " << i << " account_update: " << account << endl;
                        m.unlock();
                    }
                }
        );

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    stop = true;


    std::for_each(bank.begin(), bank.end(), [](std::thread &t) { t.join(); });
    std::for_each(client.begin(), client.end(), [](std::thread &t) { t.join(); });

    return 0;
}