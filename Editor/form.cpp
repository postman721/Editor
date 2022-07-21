#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
void Form::on_actionQuit_triggered()
{this->close();}



void Form::on_pushButton_4_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this, "Open a text file");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){QMessageBox::warning(this, "Error", "Cannot open file.");}
    else{
    QTextStream stream(&file);
    QString readme=stream.readAll();
    ui->textEdit->setText(readme);
    ui->lineEdit->setText(filename);
    file.close();}
}

void Form::on_pushButton_5_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() != QDialog::Accepted) return;
    ui->textEdit->print(&printer);
}

void Form::on_fontComboBox_currentFontChanged(const QFont &f)
{ui->textEdit->setFont(f);}


void Form::on_pushButton_2_clicked()
{ui->textEdit->zoomIn();}

void Form::on_pushButton_3_clicked()
{ui->textEdit->zoomOut();}

void Form::on_pushButton_clicked()
{ui->textEdit->copy();}

void Form::on_pushButton_7_clicked()
{ui->textEdit->paste();}

void Form::on_pushButton_8_clicked()
{ui->textEdit->undo();}

void Form::on_pushButton_9_clicked()
{ui->textEdit->redo();}


void Form::on_pushButton_11_clicked()
{   QFont font;
    font.setItalic(true);

    QTextCharFormat format;
     format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);   }

void Form::on_pushButton_10_clicked()
{
    QTextCharFormat format;
     format.setFontWeight(QFont::Bold);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);}


void Form::on_spinBox_2_valueChanged(int arg1)
{ui->textEdit->setFontPointSize(ui->spinBox_2->cleanText().toInt());}

void Form::on_pushButton_12_clicked()
{
    bool variable;
    QColor color=QColorDialog::getColor(Qt::white, this);
    if (&variable) {ui->textEdit->setTextColor(color);}
}

void Form::on_pushButton_13_clicked()
{
    QFont font;
    font.setUnderline(true);

    QTextCharFormat format;
     format.setFontWeight(QFont::Normal);
     format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);
}



void Form::on_pushButton_6_clicked()
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

void Form::on_pushButton_14_clicked()
{
    QFont font;
    font.setUnderline(false);

    QTextCharFormat format;
     format.setFontWeight(QFont::Normal);
     format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);

}

void Form::on_pushButton_15_clicked()
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

void Form::on_pushButton_16_clicked()
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


