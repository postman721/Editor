
// ++Editor is a C++ text-editor.
//Copyright (c) 2020 JJ Posti <techtimejourney.net>
//This is free software, and you are welcome to redistribute it under GPL Version 2, June 1991 OR Apache License v2.″

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{this->close();}



void MainWindow::on_pushButton_4_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this, "Open a text file");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){QMessageBox::warning(this, "Error", "Cannot open file.");}
    else{
    QTextStream stream(&file);
    QString readme=stream.readAll();
    ui->textEdit->setText(readme);
    ui->statusBar->showMessage(filename);
    file.close();}
}

void MainWindow::on_pushButton_5_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() != QDialog::Accepted) return;
    ui->textEdit->print(&printer);
}

void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{ui->textEdit->setFont(f);}


void MainWindow::on_pushButton_2_clicked()
{ui->textEdit->zoomIn();}

void MainWindow::on_pushButton_3_clicked()
{ui->textEdit->zoomOut();}

void MainWindow::on_pushButton_clicked()
{ui->textEdit->copy();}

void MainWindow::on_pushButton_7_clicked()
{ui->textEdit->paste();}

void MainWindow::on_pushButton_8_clicked()
{ui->textEdit->undo();}

void MainWindow::on_pushButton_9_clicked()
{ui->textEdit->redo();}


void MainWindow::on_pushButton_11_clicked()
{   QFont font;
    font.setItalic(true);

    QTextCharFormat format;
     format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);   }

void MainWindow::on_pushButton_10_clicked()
{
    QTextCharFormat format;
     format.setFontWeight(QFont::Bold);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{ui->textEdit->setFontPointSize(ui->spinBox_2->cleanText().toInt());}

void MainWindow::on_pushButton_12_clicked()
{
    bool variable;
    QColor color=QColorDialog::getColor(Qt::white, this);
    if (&variable) {ui->textEdit->setTextColor(color);}
}

void MainWindow::on_pushButton_13_clicked()
{
    QFont font;
    font.setUnderline(true);

    QTextCharFormat format;
     format.setFontWeight(QFont::Normal);
     format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);
}



void MainWindow::on_pushButton_6_clicked()
{
    QString filename=QFileDialog::getSaveFileName(this, "Save as");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)){QMessageBox::warning(this, "Error", "Cannot save the file.");}
    else {
    QTextStream write(&file);
    QString content= ui->textEdit->toPlainText();
    write << content;
    file.flush();
    file.close();}
}

void MainWindow::on_pushButton_14_clicked()
{
    QFont font;
    font.setUnderline(false);

    QTextCharFormat format;
     format.setFontWeight(QFont::Normal);
     format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);

}

void MainWindow::on_pushButton_15_clicked()
{
    QFont font;
    font.setUnderline(true);
    font.setBold(true);

    QTextCharFormat format;
     format.setFontWeight(QFont::Normal);
     format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);
}

void MainWindow::on_pushButton_16_clicked()
{
    QFont font;
    font.setBold(true);
    font.setItalic(true);

    QTextCharFormat format;
     format.setFontWeight(QFont::Normal);
     format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);
}
