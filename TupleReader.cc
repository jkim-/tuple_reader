#include <utility>
#include "TupleReader.h"
//ROOT Headers
#include <TBranch.h>

using std::vector;
using std::string;
using std::map;
using std::make_pair;

TupleReader::TupleReader(vector<string> var_names, 
                         string root_filename,
                         string root_treename)
    : var_names_(var_names) {
  root_file_ = new TFile(root_filename.c_str());
  root_tree_ = (TTree*) root_file_->Get(root_treename.c_str());
  SetAddresses();
}

TupleReader::~TupleReader() {
  root_file_->Close();
  delete root_file_;
}

void TupleReader::SetAddresses() {
  vector<int*> var_addresses(var_names_.size());
  for (size_t idx = 0; idx < var_names_.size(); ++idx) {
    var_vector_indexes_.insert(make_pair(var_names_[idx], idx));
    root_tree_->SetBranchAddress(var_names_[idx].c_str(), var_addresses[idx]);
  }
}

void TupleReader::next_record() {
  

}

int TupleReader::get(string var_name) {
  return 0;
}

