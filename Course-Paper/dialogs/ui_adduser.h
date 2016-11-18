/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addUser
{
public:
    QPushButton *addUserButton;
    QLineEdit *password;
    QLineEdit *username;
    QComboBox *status;
    QLabel *annotation;

    void setupUi(QDialog *addUser)
    {
        if (addUser->objectName().isEmpty())
            addUser->setObjectName(QStringLiteral("addUser"));
        addUser->resize(400, 300);
        addUserButton = new QPushButton(addUser);
        addUserButton->setObjectName(QStringLiteral("addUserButton"));
        addUserButton->setGeometry(QRect(40, 190, 327, 39));
        addUserButton->setCursor(QCursor(Qt::PointingHandCursor));
        addUserButton->setStyleSheet(QLatin1String("background:#128A42;\n"
"	color:#fff;\n"
"width: 99%;\n"
"	padding: 3%;\n"
"	background: #21A957;\n"
"	font-family: 'Arial', sans-serif;\n"
"	color: #ECECEC;\n"
"	font-size: 20px;\n"
"	font-weight:500;\n"
"	border-radius: 5px;\n"
"	margin-top:10px;"));
        password = new QLineEdit(addUser);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(40, 122, 327, 36));
        password->setStyleSheet(QLatin1String("text-align:left;\n"
"	background:#D3D3D3;;\n"
"	font-family: 'Open Sans', sans-serif;\n"
"	color: #676767;\n"
"	font-weight:600;\n"
"	font-size: 16px;\n"
"	border-radius: 5px;\n"
"	border:1px solid #DED6D6;\n"
"	width:0%;\n"
"	padding-left:2px;\n"
"	margin-top:10px;"));
        password->setEchoMode(QLineEdit::Password);
        username = new QLineEdit(addUser);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(40, 80, 327, 36));
        username->setStyleSheet(QLatin1String("text-align:left;\n"
"	background:#D3D3D3;;\n"
"	font-family: 'Open Sans', sans-serif;\n"
"	color: #676767;\n"
"	font-weight:600;\n"
"	font-size: 16px;\n"
"	border-radius: 5px;\n"
"	border:1px solid #DED6D6;\n"
"	width:0%;\n"
"	margin-top:10px;"));
        username->setEchoMode(QLineEdit::Normal);
        status = new QComboBox(addUser);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(40, 170, 321, 22));
        status->setMaxVisibleItems(3);
        status->setInsertPolicy(QComboBox::InsertAtTop);
        status->setMinimumContentsLength(0);
        annotation = new QLabel(addUser);
        annotation->setObjectName(QStringLiteral("annotation"));
        annotation->setGeometry(QRect(50, 30, 311, 41));
        QFont font;
        font.setPointSize(12);
        annotation->setFont(font);

        retranslateUi(addUser);
        QObject::connect(addUserButton, SIGNAL(clicked()), addUser, SLOT(accept()));

        QMetaObject::connectSlotsByName(addUser);
    } // setupUi

    void retranslateUi(QDialog *addUser)
    {
        addUser->setWindowTitle(QApplication::translate("addUser", "Dialog", 0));
        addUserButton->setText(QApplication::translate("addUser", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        password->setPlaceholderText(QApplication::translate("addUser", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        username->setPlaceholderText(QApplication::translate("addUser", " \320\233\320\276\320\263\320\270\320\275", 0));
        status->setCurrentText(QString());
        annotation->setText(QApplication::translate("addUser", "\320\222  \320\273\320\276\320\263\320\270\320\275\320\265 \320\270 \320\277\320\260\321\200\320\276\320\273\320\265 \320\267\320\260\320\277\321\200\320\265\321\211\320\265\320\275\321\213 \320\277\321\200\320\276\320\261\320\265\320\273\321\213.", 0));
    } // retranslateUi

};

namespace Ui {
    class addUser: public Ui_addUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
