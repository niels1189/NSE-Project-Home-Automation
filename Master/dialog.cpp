#include "dialog.h"
#include "ui_dialog.h"

#define path_to_db "C:/Users/Nitesh/Downloads/GUI-V3/Users.sqlite"
#define SQL_query "SELECT Username, Password FROM Users WHERE Username=\'" + Username +"\' AND Password=\'" + Password + "\'"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(path_to_db);
    QFileInfo checkFile(path_to_db);                                            // check if the database file already exist

    if(checkFile.isFile())
    {
        if(myDB.open())
            ui->label_status_login->setText("Connected to database file");      // Connection is OK

        else
            ui->label_status_login->setText("Failed to connect");               // Can't connect to the DB file. Path error?
    }
}

Dialog::~Dialog()
{
    delete ui;
    qDebug() << "Closing the connection to the DB";
    myDB.close(); // Close the session
}

void Dialog::on_pushButton_clicked()
{
    QString Username,Password;    // creates two variables
    Username=ui->txtUser->text(); // save the input from the user in the variable Username
    Password=ui->txtPass->text(); // save the input from the user in the variable Password

    if(!myDB.isOpen())
    {
        qDebug() << "No connection to the DB";
        return;
    }

    QSqlQuery qry;
    if(qry.exec(SQL_query)) // query from SQL, to check if both Username and Password exist within the database
    {
        if(qry.next())
        {
            ui->label_status_login->setText("Valid username and password"); // change the label to the text
            QString msg = "Username and Password is OK!";                   // create msg with a message
             qDebug() << "oii";
            QMessageBox::warning(this, "Login successful",msg);             // pop-up screen with the message
            this->~Dialog();                                                // hide the login screen

            ScreenAfterLogin ScreenAfterLogin;
            ScreenAfterLogin.setModal(true); // shows next screen
            ScreenAfterLogin.exec();



        }
        else
            ui->label_status_login->setText("Wrong username or password"); // change the label to the text
    }
}


