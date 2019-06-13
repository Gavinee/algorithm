#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QMutex>
#include <QDateTime>
#include <QTextStream>
#include <stdio.h>

#include "log_global.h"

#define LOG_IDENTIFIER "_Log.html"

#define LOG_INFO    0
#define LOG_WARNING 1
#define LOG_ERROR	2

#define DETAIL_INFO  QString::fromLocal8Bit("<.%1>@%2=>%3: ").arg(__FILE__).arg(__FUNCTION__);
#define LOGERROR(_log) Log::getInstance()->writeLog(_log,DETAIL_INFO,LOG_ERROR)
#define LOGINFO(_log) Log::getInstance()->writeLog(_log,DETAIL_INFO,LOG_INFO)
#define LOGWARNING(_log) Log::getInstance()->writeLog(_log,DETAIL_INFO,LOG_WARNING)

class LOGSHARED_EXPORT Log
{

private:
    Log();
	static Log* m_instance;
	
public:
	~Log();
	static Log* getInstance();
	void writeLog(QString _log,QString _details = "",int _flag = LOG_INFO);

private:
	void openNewLog();
	void endLog();

private:
	QFile m_log;
	QMutex m_mutex;
	QTextStream m_stream;
	int m_index;
};

#endif // LOG_H
