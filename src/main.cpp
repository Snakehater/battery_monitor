#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char **args)
{
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);

	if (rc)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		return -1;
	}
	else
	{
		fprintf(stdout, "Opened database successfully\n");
	}

	sqlite3_close(db);
	return 0;
}
