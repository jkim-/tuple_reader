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
  current_event_idx_ = 0;
  num_events_ = root_tree_->GetEntries();
  SetAddresses();
}

TupleReader::~TupleReader() {
  root_file_->Close();
  delete root_file_;
}

void TupleReader::SetAddresses() {
  var_addresses_ = vector<int*>(var_names_.size());
  for (size_t idx = 0; idx < var_names_.size(); ++idx) {
    var_vector_indexes_.insert(make_pair(var_names_[idx], idx));
    root_tree_->SetBranchAddress(var_names_[idx].c_str(), var_addresses_[idx]);
  }
}

bool TupleReader::next_record() {
  if (current_event_idx_ < num_events_) {
    if (root_tree_->GetEntry(current_event_idx_) > 0) {
      ++current_event_idx_;
      return true;
    }
  }
  return false;
}

int TupleReader::get(string var_name) {
  return 0;
}

