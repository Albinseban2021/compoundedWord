#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

bool isCompounded(const string& word, const set<string>& wordSet, unordered_map<string, bool>&& memo) {
    if (word.empty()) {
        return true;
    }
    if (memo.find(word) != memo.end()) {
        return memo[word];
    }
    for (int i = 1; i <= word.length(); i++) {
        string prefix = word.substr(0, i);
        if (wordSet.find(prefix) != wordSet.end()) {
            string suffix = word.substr(i);
            if (wordSet.find(suffix) != wordSet.end() || isCompounded(suffix, wordSet, std::move(memo))) {
                memo[word] = true;
                return true;
            }
        }
    }
    memo[word] = false;
    return false;
}


string findLongestCompoundedWord(vector<string>& words) {
    set<string> wordSet(words.begin(), words.end());
    for (int i = words.size() - 1; i >= 0; i--) {
        string word = words[i];
        wordSet.erase(word); 
        if (isCompounded(word, wordSet, unordered_map<string, bool>())) {
            return word;
        }
        wordSet.insert(word); 
    }
    return "";
}

string findSecondLongestCompoundedWord(vector<string>& words, const string& longestWord) {
    set<string> wordSet(words.begin(), words.end());
    bool longestFound = false;
    for (int i = words.size() - 1; i >= 0; i--) {
        string word = words[i];
        wordSet.erase(word); 
        if (isCompounded(word, wordSet, unordered_map<string, bool>())) {
            if (longestFound) {
                return word;
            } else if (word == longestWord) {
                longestFound = true;
            }
        }
        wordSet.insert(word); 
    }
    return "";
}

int main() {
     auto start = high_resolution_clock::now();
    cout << "Enter a list of words (empty line to stop): " << endl;
    vector<string> words;
    string input;

    while (true) {
        getline(cin, input);
        if (input.empty()) {
            break;
        }
        words.push_back(input);
    }
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });

   string longestCompoundedWord = findLongestCompoundedWord(words);
string secondLongestCompoundedWord = findSecondLongestCompoundedWord(words, longestCompoundedWord);
  auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Longest Compound Word: " << longestCompoundedWord << endl;
    cout << "Second Longest Compound Word: " << secondLongestCompoundedWord << endl;
    cout<< "Time Time Taken to process "<<duration;
    return 0;
}
