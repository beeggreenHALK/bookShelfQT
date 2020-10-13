#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <BShelf.h>
#include <PrintBook.h>
#include <Shelf.h>
#include <vector>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_BShelf_add_clicked();

    void on_listWidget_BShelf_itemClicked(QListWidgetItem *item);

    void on_pushButton_Shelf_add_clicked();

private:
    Ui::MainWindow *ui;
    vector<BookShelf> bookshelfs;//Шкафы
    int bShelfID;
    int shelfID;
    int bookID;
};
#endif // MAINWINDOW_H
