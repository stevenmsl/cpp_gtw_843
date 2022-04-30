#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
#include <sstream>
using namespace sol830;
using namespace std;

/*takeaways
  - implement our match method to reduce the list of words
  - secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]
    - we randomly pick a word let say it's abcczz
    - we call master.guess and get 4 back
    - we then calcualte the distance between every word and guess word
      - "acckzz" <-> "abcczz"  4
      - "ccbazz" <-> "abcczz"  4
      - "eiowzz" <-> "abcczz"  4
      - "abcczz" <-> "abcczz"  0
    - so the secret will be in a reduced list ["acckzz","ccbazz","eiowzz"]
      why? the distance is the same as the master.guess told us, so the
      secret must be among them
    - continue picking a word randomly from the reduced list of words
      to further reduce the list until you find the secret
  - why can you find the secret within 10 tries?
    - you choose the guess word randomly for an ever reducing list of words
    - the math behind it says the list will be reduced in a very fast pace
      to ahcieve this
*/
Master::Master(string secret, vector<string> &words)
{
  wordSet = unordered_set<string>(words.begin(), words.end());
  _secret = secret;
}

int Master::guess(string s)
{
  if (!wordSet.count(s))
    return -1;
  auto score = 0;
  for (auto i = 0; i < s.size(); i++)
    if (_secret[i] == s[i])
      score++;
  return score;
}

int Solution::match(string &source, string &target)
{
  auto score = 0;

  for (auto i = 0; i < source.size(); i++)
    if (source[i] == target[i])
      score++;
  return score;
}

string Solution::find(vector<string> &words, Master &master)
{
  /*use current time as seed for random generator */
  srand(time(nullptr));

  for (auto i = 0, score = 0; i < 10; i++)
  {
    auto guess = words[rand() % 6];
    score = master.guess(guess);
    if (score == 6)
      return guess;
    auto reduced = vector<string>();
    for (auto w : words)
      if (match(w, guess) == score)
        reduced.push_back(w);
  }

  return "";
}