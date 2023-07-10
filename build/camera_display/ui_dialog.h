/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QComboBox *pipeTypeComboBox;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_17;
    QDateEdit *dateEdit;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QTextEdit *startNumEdit;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QTextEdit *pipeLengthEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QTextEdit *placeEdit;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QTextEdit *endNumEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QTextEdit *pipeDEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QTextEdit *unitEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *direcComboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QTextEdit *numEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTextEdit *nameEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QComboBox *pipeMaterialComboBox;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_14;
    QTextEdit *textEdit_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_15;
    QTextEdit *textEdit_14;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QTextEdit *personEdit;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(640, 480);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 440, 621, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 100, 581, 321));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_9->addWidget(label_10);

        pipeTypeComboBox = new QComboBox(frame);
        pipeTypeComboBox->addItem(QString());
        pipeTypeComboBox->addItem(QString());
        pipeTypeComboBox->setObjectName(QString::fromUtf8("pipeTypeComboBox"));

        horizontalLayout_9->addWidget(pipeTypeComboBox);


        gridLayout->addLayout(horizontalLayout_9, 11, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 10, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_17 = new QLabel(frame);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(74, 16777215));

        horizontalLayout_15->addWidget(label_17);

        dateEdit = new QDateEdit(frame);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_15->addWidget(dateEdit);


        gridLayout->addLayout(horizontalLayout_15, 5, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 8, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 12, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        startNumEdit = new QTextEdit(frame);
        startNumEdit->setObjectName(QString::fromUtf8("startNumEdit"));

        horizontalLayout_7->addWidget(startNumEdit);


        gridLayout->addLayout(horizontalLayout_7, 9, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 3, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_12->addWidget(label_13);

        pipeLengthEdit = new QTextEdit(frame);
        pipeLengthEdit->setObjectName(QString::fromUtf8("pipeLengthEdit"));

        horizontalLayout_12->addWidget(pipeLengthEdit);


        gridLayout->addLayout(horizontalLayout_12, 15, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        placeEdit = new QTextEdit(frame);
        placeEdit->setObjectName(QString::fromUtf8("placeEdit"));

        horizontalLayout_2->addWidget(placeEdit);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 14, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        endNumEdit = new QTextEdit(frame);
        endNumEdit->setObjectName(QString::fromUtf8("endNumEdit"));

        horizontalLayout_8->addWidget(endNumEdit);


        gridLayout->addLayout(horizontalLayout_8, 9, 2, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_11->addWidget(label_12);

        pipeDEdit = new QTextEdit(frame);
        pipeDEdit->setObjectName(QString::fromUtf8("pipeDEdit"));

        horizontalLayout_11->addWidget(pipeDEdit);


        gridLayout->addLayout(horizontalLayout_11, 7, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        unitEdit = new QTextEdit(frame);
        unitEdit->setObjectName(QString::fromUtf8("unitEdit"));

        horizontalLayout_4->addWidget(unitEdit);


        gridLayout->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_5->addWidget(label_6);

        direcComboBox = new QComboBox(frame);
        direcComboBox->addItem(QString());
        direcComboBox->addItem(QString());
        direcComboBox->setObjectName(QString::fromUtf8("direcComboBox"));

        horizontalLayout_5->addWidget(direcComboBox);


        gridLayout->addLayout(horizontalLayout_5, 7, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        numEdit = new QTextEdit(frame);
        numEdit->setObjectName(QString::fromUtf8("numEdit"));

        horizontalLayout_3->addWidget(numEdit);


        gridLayout->addLayout(horizontalLayout_3, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        nameEdit = new QTextEdit(frame);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_10->addWidget(label_11);

        pipeMaterialComboBox = new QComboBox(frame);
        pipeMaterialComboBox->addItem(QString());
        pipeMaterialComboBox->addItem(QString());
        pipeMaterialComboBox->addItem(QString());
        pipeMaterialComboBox->setObjectName(QString::fromUtf8("pipeMaterialComboBox"));

        horizontalLayout_10->addWidget(pipeMaterialComboBox);


        gridLayout->addLayout(horizontalLayout_10, 11, 2, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_13->addWidget(label_14);

        textEdit_13 = new QTextEdit(frame);
        textEdit_13->setObjectName(QString::fromUtf8("textEdit_13"));

        horizontalLayout_13->addWidget(textEdit_13);


        gridLayout->addLayout(horizontalLayout_13, 13, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_14->addWidget(label_15);

        textEdit_14 = new QTextEdit(frame);
        textEdit_14->setObjectName(QString::fromUtf8("textEdit_14"));

        horizontalLayout_14->addWidget(textEdit_14);


        gridLayout->addLayout(horizontalLayout_14, 13, 2, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        personEdit = new QTextEdit(frame);
        personEdit->setObjectName(QString::fromUtf8("personEdit"));

        horizontalLayout_6->addWidget(personEdit);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 40, 291, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_10->setText(QCoreApplication::translate("Dialog", "\347\256\241\351\201\223\347\261\273\345\236\213    ", nullptr));
        pipeTypeComboBox->setItemText(0, QCoreApplication::translate("Dialog", "\351\233\250\346\260\264\347\256\241\351\201\223", nullptr));
        pipeTypeComboBox->setItemText(1, QCoreApplication::translate("Dialog", "\346\261\241\346\260\264\347\256\241\351\201\223", nullptr));

        label_17->setText(QCoreApplication::translate("Dialog", "\346\243\200\346\265\213\346\227\245\346\234\237", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog", "\350\265\267\345\247\213\344\272\225\345\217\267    ", nullptr));
        startNumEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">YS45400151</p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("Dialog", "\347\256\241\346\256\265\351\225\277         ", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\346\243\200\346\265\213\345\234\260\347\202\271    ", nullptr));
        placeEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\270\255\345\261\261\346\235\221\350\267\257</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog", "\347\273\223\346\235\237\344\272\225\345\217\267    ", nullptr));
        endNumEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">YS45400146</p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("Dialog", "\347\256\241\345\276\204             ", nullptr));
        pipeDEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">450mm</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "\346\243\200\346\265\213\345\215\225\344\275\215    ", nullptr));
        unitEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\230\206\345\261\261\345\270\202\346\224\277\345\267\245\347\250\213\346\234\211\351\231\220\345\205\254\345\217\270</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "\346\243\200\346\265\213\346\226\271\345\220\221    ", nullptr));
        direcComboBox->setItemText(0, QCoreApplication::translate("Dialog", "\351\241\272\346\265\201", nullptr));
        direcComboBox->setItemText(1, QCoreApplication::translate("Dialog", "\351\200\206\346\265\201", nullptr));

        label_4->setText(QCoreApplication::translate("Dialog", "\344\273\273\345\212\241\347\274\226\345\217\267    ", nullptr));
        numEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\270\255\345\261\261\346\235\221\350\267\257\351\235\236\345\274\200\346\214\226\344\277\256\345\244\215</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\344\273\273\345\212\241\345\220\215\347\247\260    ", nullptr));
        nameEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\270\255\345\261\261\346\235\221\350\267\257</p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("Dialog", "\347\256\241\351\201\223\346\235\220\350\264\250    ", nullptr));
        pipeMaterialComboBox->setItemText(0, QCoreApplication::translate("Dialog", "\347\240\274", nullptr));
        pipeMaterialComboBox->setItemText(1, QCoreApplication::translate("Dialog", "PE", nullptr));
        pipeMaterialComboBox->setItemText(2, QCoreApplication::translate("Dialog", "PVC", nullptr));

        label_14->setText(QCoreApplication::translate("Dialog", "\350\265\267\345\247\213\344\272\225\345\237\213\346\267\261", nullptr));
        label_15->setText(QCoreApplication::translate("Dialog", "\347\273\223\346\235\237\344\272\225\345\237\213\346\267\261", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "\346\243\200\346\265\213\345\221\230        ", nullptr));
        personEdit->setHtml(QCoreApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\241\276\346\265\267\345\205\265</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\346\243\200\346\265\213\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
