#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<sqlite3.h>

using namespace std;

const char * select_query = "SELECT ID,USERNAME FROM USERS WHERE USERNAME LIKE (?2)";

int main(){
    sqlite3 * database;
    sqlite3_stmt * select_query_stmt;
    string input;
    int step_result;

    sqlite3_open("database.db",&database);

    sqlite3_prepare_v2(database, select_query, strlen(select_query), &select_query_stmt, NULL);
    cin>>input;
    sqlite3_bind_text(select_query_stmt,2,input.c_str(),input.length(),NULL);
    cout << endl;
    
    while(true){
        step_result = sqlite3_step(select_query_stmt);

        if (step_result == SQLITE_ROW){

            int id;
            const unsigned char * text;
            id = sqlite3_column_int(select_query_stmt,0);
            text = sqlite3_column_text(select_query_stmt,1);
            //cout << "Alra colonna" << endl;
            cout << "username: " << text << " id: " << id << endl;
        }
        else if (step_result == SQLITE_DONE) {

            cout <<  "Fine" << endl;
            break;
        }
        else {
            cout << "ERRORE!" << endl;
            exit (1);
        }
        
    }

    sqlite3_finalize(select_query_stmt);
    sqlite3_close(database);

    return 0;
}
