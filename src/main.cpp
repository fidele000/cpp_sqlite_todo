#include <iostream>
#include <sqlite3.h>
using namespace std;


static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc=sqlite3_open("data.db",&db);
    if(rc){
        cout<<"Can't open Database "<<sqlite3_errmsg(db)<<endl;
        sqlite3_close(db);
        return 1;
    }
    rc=sqlite3_exec(db,"CREATE TABLE todos (id integer PRIMARY KEY AUTOINCREMENT,title varchar(250), description text NOT NULL,status boolean);",callback,0,&zErrMsg);
    if( rc!=SQLITE_OK ){
      cout<<"SQL error: "<<zErrMsg<<endl;
      sqlite3_free(zErrMsg);
    }
    rc=sqlite3_exec(db,"INSERT INTO todos (description,status) VALUES('Ndakora byinshi',true)",callback,0,&zErrMsg);
    if( rc!=SQLITE_OK ){
      cout<<"SQL error: "<<zErrMsg<<endl;
      sqlite3_free(zErrMsg);
    }
    
    sqlite3_close(db);
    cout<<"Hello Bro"<<endl;
}