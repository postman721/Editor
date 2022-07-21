#ifndef FORM_H
#define FORM_H

#include <QWidget>
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
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_actionQuit_triggered();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();


private:
    Ui::Form *ui;
};

#endif // FORM_H
