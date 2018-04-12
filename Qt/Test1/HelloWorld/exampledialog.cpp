#include "exampledialog.h"
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QSpacerItem>
#include <QGroupBox>
#include <QRadioButton>
#include <QtWidgets>
#include <QButtonGroup>
#include <QAbstractButton>
#include <QScopedPointer>
#include <QObject>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QString>


ExampleDialog::ExampleDialog(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Text to PDF");
    this->setMinimumWidth(400);
    this->setMinimumHeight(400);

    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    printerOptions = new QComboBox();
    rbtn1 = new QRadioButton("Landscape");
    rbtn2 = new QRadioButton("Portrait");
    rbtn3 = new QRadioButton("Black and White");
    rbtn4 = new QRadioButton("Color");
    printBtn = new QPushButton("Print");
    cancelBtn = new QPushButton("Cancel");
    textBox = new QTextEdit();
    printer = new QPrinter(QPrinter::PrinterResolution);

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(new QLabel("Printer:"));
    topLayout->addWidget(printerOptions);
    printerOptions->addItem("PDF", QPrinter::PdfFormat);
    outerLayout->addLayout(topLayout);

    QHBoxLayout *groupLayout = new QHBoxLayout();

    QGroupBox *orientationGroup = new QGroupBox();
    QVBoxLayout *orientationLayout = new QVBoxLayout(orientationGroup);
    orientationLayout->addWidget(new QLabel("Page Orientation"));
    orientationLayout->addWidget(rbtn1);
    orientationLayout->addWidget(rbtn2);
    groupLayout->addWidget(orientationGroup);

    QGroupBox *colorGroup = new QGroupBox();
    QVBoxLayout *colorLayout = new QVBoxLayout(colorGroup);
    colorLayout->addWidget(new QLabel("Color Options"));
    colorLayout->addWidget(rbtn3);
    colorLayout->addWidget(rbtn4);
    groupLayout->addWidget(colorGroup);
    outerLayout->addLayout(groupLayout);

    QVBoxLayout *textBoxLayout = new QVBoxLayout();
    textBoxLayout->addWidget(new QLabel("Text"));
    textBoxLayout->addWidget(textBox);
    outerLayout->addLayout(textBoxLayout);

    outerLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addSpacerItem(new QSpacerItem(1,1,QSizePolicy::Expanding, QSizePolicy::Fixed));
    buttonLayout->addWidget(printBtn);
    buttonLayout->addWidget(cancelBtn);
    outerLayout->addLayout(buttonLayout);

    connect(printBtn, SIGNAL(clicked(bool)), this, SLOT(handlePrintButton()));
    connect(cancelBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(rbtn1, &QPushButton::toggled, this, [=]{ this->printer->setOrientation(printer->Landscape); qInfo() << "rbtn1"; });
    connect(rbtn2, &QPushButton::toggled, this, [=]{ this->printer->setOrientation(printer->Portrait); qInfo() << "rbtn2"; });
    connect(rbtn3, &QPushButton::toggled, this, [=]{ this->printer->setColorMode(QPrinter::GrayScale); qInfo() << "rbtn3"; });
    connect(rbtn4, &QPushButton::toggled, this, [=]{ this->printer->setColorMode(QPrinter::Color); qInfo() << "rbtn4"; });
//    connect(printerOptions, &QComboBox::currentTextChanged, this, [=]{ this->printer->setOutputFormat(this->printerOptions->currentData()); qInfo() << "combo"; });

    rbtn2->setChecked(true);
    rbtn3->setChecked(true);

}

void ExampleDialog::handlePrintButton() {
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        printer->setPaperSize(QPrinter::A4);

        printer->setOutputFileName(fileName);

//        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
//        connect(manager, SIGNAL(finished(QNetworkReply*)),
//                this, SLOT(replyFinished(QNetworkReply*)));
//        QNetworkReply *response(manager->get(QNetworkRequest(QUrl("https://stackoverflow.com"))));
//        QString html = response->readAll();
        QString html = textBox->toHtml();

        QTextDocument doc;

        doc.setHtml(html);
        doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(printer);
}
