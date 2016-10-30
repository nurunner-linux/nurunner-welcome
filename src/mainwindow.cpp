/*
* This file is part of Nurunner Welcome
* Copyright (C) 2016 Matthew Kowal
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readme.h"
#include <QGraphicsScene>
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>

#include "unixcommand.h"
#include "terminal.h"
#include "pacmanexec.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList command;
    command.append("rm ~/.config/autostart/nurunner-welcome.desktop");
    m_unixCommand = new UnixCommand(this);
    m_unixCommand->runCommandInTerminalAsNormalUser(command);

    if (!(m_unixCommand->isPackageInstalled("calamares"))){
        ui->setupUi(this);
    }else{
        QApplication::quit();
        parent->close();
    }


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_mirrorUpdateButton_clicked()
{
    QStringList commandsToRun;
    commandsToRun.append("/usr/bin/rankmirrors -g");
    ui->mirrorUpdateButton->setEnabled(false);
    ui->tabWidget->setEnabled(false);
    m_unixCommand = new UnixCommand(this);
    m_unixCommand->runCommandInTerminal(commandsToRun);
    ui->tabWidget->setEnabled(true);


}

void MainWindow::on_softwareUpdateButton_clicked()
{
    ui->softwareUpdateButton->setEnabled(false);
    ui->tabWidget->setEnabled(false);
    m_pacmanExec = new PacmanExec;
    m_pacmanExec->doSystemUpgradeInTerminal();
    ui->tabWidget->setEnabled(true);
}

void MainWindow::on_gotoIndex2Button_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void MainWindow::on_installSoftwareButton_clicked()
{
    QString packagesToInstall = "";

    if (ui->chromeCheckbox->isChecked()){
        packagesToInstall.append(" chromium");
    }
    if (ui->vivaldiCheckbox->isChecked()){
        packagesToInstall.append(" vivaldi vivaldi-ffmpeg-codecs");
    }
    if (ui->dropboxCheckbox->isChecked()){
        packagesToInstall.append(" dropbox");
    }
    if (ui->dropboxCheckbox->isChecked()){
        packagesToInstall.append(" dropbox");
    }
    if (ui->megasyncCheckbox->isChecked()){
        packagesToInstall.append(" megasync");
    }
    if (ui->spotifyCheckbox->isChecked()){
        packagesToInstall.append(" spotify");
    }
    if (ui->chromeWidevineButton->isChecked()){
        packagesToInstall.append(" chromium-widevine");
    }
    if (ui->vivaldiWidevineButton->isChecked()){
        packagesToInstall.append(" vivaldi-widevine");
    }
    if (ui->vscodeButton->isChecked()){
        packagesToInstall.append(" visual-studio-code");
    }

    if (packagesToInstall == ""){

    }else{
        ui->installSoftwareButton->setEnabled(false);
        m_pacmanExec = new PacmanExec;
        ui->tabWidget->setEnabled(false);
        m_pacmanExec->doInstallInTerminal(packagesToInstall);
        ui->tabWidget->setEnabled(true);
    }
}

void MainWindow::on_chromeCheckbox_clicked()
{
    if (ui->chromeCheckbox->isChecked()){
        ui->chromeWidevineButton->setEnabled(true);
    }else{
        ui->chromeWidevineButton->setEnabled(false);
        ui->chromeWidevineButton->setChecked(false);
    }
}

void MainWindow::on_gotoIndex3_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    QDesktopServices::openUrl(QUrl("https://nurunner.org/forum", QUrl::TolerantMode));
}

void MainWindow::on_pushButton_5_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/nurunner-linux", QUrl::TolerantMode));
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_pressed()
{

}

void MainWindow::on_vivaldiCheckbox_clicked()
{
    if (ui->vivaldiCheckbox->isChecked()){
        ui->vivaldiWidevineButton->setEnabled(true);
    }else{
        ui->vivaldiWidevineButton->setEnabled(false);
        ui->vivaldiWidevineButton->setChecked(false);
    }
}

void MainWindow::on_readmeButton_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}
