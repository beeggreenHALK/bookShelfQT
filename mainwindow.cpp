#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Начальное состояние
    bookID=0;
    bShelfID=0;
    shelfID=0;
    ui->groupBox_Book->setEnabled(false);
     ui->groupBox_Shelf->setEnabled(false);
     ui->pushButton_BShelf_del->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_BShelf_add_clicked()
{
    //Создать шкаф
    BookShelf bs;
    //Добавить шкаф в список
    bookshelfs.push_back(bs);
    ui->listWidget_BShelf->addItem(QString::number(bookshelfs.size()));
}

void MainWindow::on_listWidget_BShelf_itemClicked(QListWidgetItem *item)
{
    //Получить ID шкафа
    bShelfID = item->text().toInt();
    //активировать элементы интерфейса
    ui->pushButton_BShelf_del->setEnabled(true);
    ui->groupBox_Shelf->setEnabled(true);
    ui->pushButton_Shelf_del->setEnabled(false);
    //Получить кол-во полок
    int shelfN = bookshelfs[bShelfID-1].getShelfNumber();
    //Отчистьть список полок
    ui->listWidget_Shelf->clear();
    ui->listWidget_Book->clear();
    //Наполнить список полок
    if(shelfN>0){
        for(int i=1;i<=shelfN;i++){
            ui->listWidget_Shelf->addItem(QString::number(i));
        }
    }
}

void MainWindow::on_pushButton_Shelf_add_clicked()
{
    //Создать полку
    Shelf shelf;
    //Добавить полку в шкаф
    bookshelfs[bShelfID-1].addShelf();
    //Обновить список
    int shelfN = bookshelfs[bShelfID-1].getShelfNumber();
    ui->listWidget_Shelf->addItem(QString::number(shelfN));
}
