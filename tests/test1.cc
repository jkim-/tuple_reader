#include <TupleReader.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  string root_filename = "/home/jkim/raid13/ntp/sp11444r1/root/1.root";
  string root_treename = "ntp1";
  vector<string> var_names = {"mcLen", "nY"};

  cout << "Instantiating a TupleReader object: ";
  TupleReader tr(var_names, root_filename, root_treename);
  cout << "Done. " << endl;

  size_t idx = 0;
  while (tr.next_record()) {
    if (idx % 100 == 0) {
      cout << "Event #" << idx;
      cout << " has mcLen = " << tr.get(var_names[0]);
      cout << " and nY = " << tr.get(var_names[1]) << endl;
    }
    idx++;
  }

  return 0;
}
