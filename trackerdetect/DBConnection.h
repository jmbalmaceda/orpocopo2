#pragma once
#ifdef _WIN32
	#include <mysql.h>
#else
	#include <mysql/mysql.h>
#endif
#include <string>

using namespace std;


struct ConnectionData
{
	string server;
	string user;
	string password;
	string database;
	};
	

class DBConnection
{
private:
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	string cacheQuery;
public:
	DBConnection(ConnectionData data);
	~DBConnection(void);

	/// Formato ejemplo 2015-06-29 00:43:00
	string getCurrentTimeAsString();

	bool insertPickUpInformation(int frame, int count_blobs, int blob_id, int blob_x, int blob_y, int blob_depth, int blob_hand_id, int blob_hand_x, int blob_hand_y, int blob_hand_depth);

	bool insertPickUpInformation(int frame, int count_blobs, int blob_id, int blob_x, int blob_y, int blob_depth);

	string getLastPickupId();

	bool insertLog(string log);
	
	bool writeCache();

	struct tm * startProcessing(struct tm*);
};

