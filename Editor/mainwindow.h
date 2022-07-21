#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QString>
#include <QtWidgets>
#include <QtPrintSupport>
#include <QPrintDialog>
#include <QPrinter>
#include <QCoreApplication>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <form.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_tabWidget_tabBarDoubleClicked(int index);

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
