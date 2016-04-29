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
    if (idx % 1000 == 0) cout << "Event #" << idx << endl;
    idx++;
  }

  return 0;
}
