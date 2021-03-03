#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void print(vector<string> const &vec) {
    for (auto v: vec) {
        cout << v << "\n";
    }
}


vector<string> split(const string &str, const string &delim) {

    vector<string> tokens;
    int start = 0;
    int end = str.find(delim);

    while (end != string::npos) {
        string token = str.substr(start, end - start);
        tokens.push_back(token);

        start = end + delim.length();
        end = str.find(delim, start);
    }
    tokens.push_back(str.substr(start, end));

    print(tokens);

    return tokens;
}


vector< vector<string> > tokenize(const string &file_path) {

    vector< vector<string> > tokenized_text;
    ifstream text_file (file_path.c_str());

    vector<string> lines;
    string line;

    while(getline(text_file, line)) {
        lines.push_back(string(line));
    }

    for (auto curr_line: lines) {
        cout << curr_line << "\n";

        vector<string> tokens = split(curr_line, " ");
        tokenized_text.push_back(tokens);
    }

    return tokenized_text;
}

int main() {    

    vector< vector<string> > tokens = tokenize("./data/kaggle_symptoms.txt");

    return 0;
}