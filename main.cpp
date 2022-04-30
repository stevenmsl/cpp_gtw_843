#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol830;

/*
Example 1:
Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]

Explanation:

master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.

We made 5 calls to master.guess and one of them was the secret, so we pass the test case.
*/
tuple<string, vector<string>>
testFixture1()
{
  return make_tuple("acckzz",
                    vector<string>{"acckzz", "ccbazz", "eiowzz", "abcczz"});
}

void test1()
{
  auto f = testFixture1();
  auto master = Master(get<0>(f), get<1>(f));
  auto words = get<1>(f);

  Solution sol;

  cout << "Expect to see " << get<0>(f) << ": " << sol.find(words, master) << endl;
}

void testMaster()
{
  auto f = testFixture1();
  auto master = Master(get<0>(f), get<1>(f));
  auto words = get<1>(f);
  cout << "Expect to see 6: " << master.guess(words[0]) << endl;
  cout << "Expect to see 3: " << master.guess(words[1]) << endl;
  cout << "Expect to see -1:" << master.guess("aaaaaa") << endl;
}

main()
{
  test1();
  // testMaster();
  return 0;
}