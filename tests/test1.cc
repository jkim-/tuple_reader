#include <TupleReader.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  string root_filename = "/home/jkim/raid13/ntp/sp11444r1/root/1.root";
  string root_treename = "ntp1";
  vector<string> var_names = {"mcLen", "nY"};

  TupleReader tr(var_names, root_filename, root_treename);
  return 0;
}
