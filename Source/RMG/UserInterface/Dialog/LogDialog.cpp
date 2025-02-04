/*
 * Rosalie's Mupen GUI - https://github.com/Rosalie241/RMG
 *  Copyright (C) 2020 Rosalie Wanders <rosalie@mailbox.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3.
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include "LogDialog.hpp"

#include <QMessageBox>
#include <QFileInfo>
#include <QFont>
#include <QIcon>

using namespace UserInterface::Dialog;

LogDialog::LogDialog(QWidget *parent) : QDialog(parent)
{
    this->setupUi(this);
    this->setWindowIcon(QIcon(":Resource/RMG.png"));

    QFont font("monospace");
    this->plainTextEdit->setFont(font);
}

LogDialog::~LogDialog(void)
{
}

void LogDialog::AddLogLine(CoreDebugMessageType type, QString context, QString line)
{
    QString text;

    text = context;

    switch (type)
    {
    case CoreDebugMessageType::Error:
        text += "[ERROR]   ";
        break;
    case CoreDebugMessageType::Info:
        text += "[INFO]    ";
        break;
    case CoreDebugMessageType::Verbose:
        text += "[VERBOSE] ";
        break;
    case CoreDebugMessageType::Warning:
        text += "[WARNING] ";
        break;
    case CoreDebugMessageType::Status:
        text += "[STATUS]  ";
        break;
    }

    text += line;

    this->plainTextEdit->appendPlainText(text);
}

void LogDialog::Clear(void)
{
    this->plainTextEdit->clear();
}

