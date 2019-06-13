#include "log.h"
#include <QDir>
#include <QSettings>
#include <QCoreApplication>
#include <QDebug>

Log* Log::m_instance = new Log;

Log* Log::getInstance()
{
	return m_instance;
}

Log::Log()
{
	QDir _applicationDir(QCoreApplication::applicationDirPath());
	_applicationDir.cdUp();

	if (!_applicationDir.exists(_applicationDir.path() + "/log"))
	{
		_applicationDir.mkpath(_applicationDir.path() + "/log");
	}

	_applicationDir.cd("log");
	QString date = QDate::currentDate().currentDate().toString("yyyy-MM-dd");
	QString time = QTime::currentTime().currentTime().toString("hh-mm-ss");
	QString fileNamelog;
	fileNamelog += date;
	fileNamelog += " ";
	fileNamelog += time;
	fileNamelog += LOG_IDENTIFIER;
	QString _path = _applicationDir.path() + "/" + date;
	if (!_applicationDir.exists(_path))
	{
		_applicationDir.mkpath(_path);
	}
	_applicationDir.cd(date);

	m_index = 0;

	m_log.setFileName(_applicationDir.path() + "/" + fileNamelog);
	if (m_log.exists())m_log.remove();
	if (m_log.open(QIODevice::ReadWrite | QIODevice::Text | QFile::Append))
	{
		m_stream.setDevice(&m_log);
		QString _logTitle = QString::fromLocal8Bit("<html>\n<head>\n<title>ÈÕÖ¾¼ÇÂ¼</title>\n</head>\n<body>\n");
		m_stream << _logTitle;
	}
	else
	{
		QString _err = m_log.errorString();
	}
}

Log::~Log()
{
	endLog();
}

void Log::writeLog(QString _log, QString _details /* = "" */, int _flag /* = LOG_INFO */)
{
	QString time = QTime::currentTime().toString("hh:mm:ss");
	m_mutex.lock();
	if (_flag == LOG_INFO)
	{
		m_stream << "<br><font size=\"3\" color=\"#459EF6\"family= \"Î¢ÈíÑÅºÚ\">" << "Index: " << m_index << "  Time-->" << time << " " <<
			_details << _log << "</font>";
	}
	else if (_flag == LOG_WARNING)
	{
		m_stream << "<br><font size = \"3\" color=\"#0000FF\"family= \"Î¢ÈíÑÅºÚ\">" << "Index: " << m_index << "Time-->"
			<< time << " " << _details << _log << "</font>";
	}
	m_stream.flush();
	m_log.flush();
	m_index += 1;
	m_mutex.unlock();
}

void Log::endLog()
{
	if (m_log.isOpen())
	{
		m_stream << "</body>";
		m_stream.flush();
		m_log.flush();
		m_log.close();
	}
}
