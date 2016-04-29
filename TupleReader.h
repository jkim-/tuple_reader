// This class accepts a vector of strings containing variable names
// for integer columns in the ROOT files.
// It allocates appropriate memories using SetBranchAddress and 
// retains a map from the name to memory location.
// It also provides a next_record() method that calls GetEntry(i),
// which loads the specified variables from the ROOT file into the
// memory allocated previously. 
// Lastly, it provides a get function, which accepts the name of 
// the variables and returns a pointer to the memory, to be passed
// to the inserter to the database.
#ifndef TUPLE_READER_H
#define TUPLE_READER_H

#include <vector>
#include <string>
#include <map>

//ROOT Headers
#include <TDirectory.h>
#include <TFile.h>
#include <TTree.h>

class TupleReader {
  public:
    TupleReader(std::vector<std::string> var_names, 
                std::string root_filename,
                std::string root_treename);
    ~TupleReader();

    bool next_record();
    int get(std::string var_name);

  private:
    void SetAddresses();

    std::vector<std::string> var_names_;
    TFile *root_file_;
    TTree *root_tree_;
    std::vector<int*> var_addresses_;
    std::map<std::string, size_t> var_vector_indexes_;
    int current_event_idx_ = 0;
    int num_events_ = 0;
};

#endif
