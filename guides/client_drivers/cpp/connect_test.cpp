// Trivial example

#include <iostream>

#include  "sqream.h"

int main () {

   sqream::driver sqc;

   // Connection parameters: Hostname, Port, Use SSL, Username, Password,
   // Database name, Service name
   sqc.connect("127.0.0.1", 5000, false, "rhendricks", "Tr0ub4dor&3",
               "raviga", "sqream");

   // create table with data
   run_direct_query(&sqc, "CREATE TABLE test_table (x int)");
   run_direct_query(&sqc, "INSERT INTO test_table VALUES (5), (6), (7), (8)");

   // query it
   sqc.new_query("SELECT * FROM test_table");
   sqc.execute_query();

   // See the results
   while (sqc.next_query_row()) {
       std::cout << "Received: " << sqc.get_int(0) << std::endl;
   }

   sqc.finish_query();

   // Close the connection completely
   sqc.disconnect();

}
