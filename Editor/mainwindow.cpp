
// ++Editor is a C++ text-editor.
//Copyright (c) 2020 JJ Posti <techtimejourney.net>
// This is version 2, released on July 2022.
//This is free software, and you are welcome to redistribute it under GPL Version 2, June 1991 OR Apache License v2.″

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->addTab(new Form(), QString("Tab %0").arg(ui->tabWidget->count() +1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() -1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_tabBarDoubleClicked(int index)
{
    ui->tabWidget->addTab(new Form(), QString("Tab %0").arg(ui->tabWidget->count() +1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() -1);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(index > 0){
    ui->tabWidget->removeTab(index);}
}
