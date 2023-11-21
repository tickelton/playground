/*
# Attribute Parser

This challenge works with a custom-designed markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

The closing tags follow the format:

</tag-name>

The attributes are referenced as:

tag1~value
tag1.tag2~name

Given the source code in HRML format consisting of N lines, answer Q queries. For each query, print the value of the attribute specified. Print "Not Found!" if the attribute does not exist.

## Example

HRML listing
<tag1 value = "value">
<tag2 name = "name">
<tag3 another="another" final="final">
</tag3>
</tag2>
</tag1>

Queries
tag1~value
tag1.tag2.tag3~name
tag1.tag2~value

Here, tag2 is nested within tag1, so attributes of tag2 are accessed as tag1.tag2~<attribute>. Results of the queries are:

Query                 Value
tag1~value            "value"
tag1.tag2.tag3~name   "Not Found!"
tag1.tag2.tag3~final  "final"

## Input Format

The first line consists of two space separated integers, N and Q. N specifies the number of lines in the HRML source program.
Q specifies the number of queries.

The following N lines consist of either an opening tag with zero or more attributes or a closing tag. There is a space after the tag-name, attribute-name, '=' and value.There is no space after the last value. If there are no attributes there is no space after tag name.

Q queries follow. Each query consists of string that references an attribute in the source program. More formally, each query is of the form tag(i1).tag(i2).tag(i3)....tag(im)~attr-name where m>=1 and tag(i1), tag(i2), ... tag(im) are valid tags in the input.

## Constraints

* 1 <= N <= 20
* 1 <= Q <= 20
* Each line in the source program contains, at most, 200 characters.
* Every reference to the attributes in the Q queries contains at most 200 characters.
* All tag names are unique and the HRML source program is logically correct, i.e. valid nesting.
* A tag can may have no attributes.

## Output Format

Print the value of the attribute for each query. Print "Not Found!" without quotes if the attribute does not exist.

## Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

## Sample Output

Name1
Not Found!
HelloWorld

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

std::string & ltrim(std::string & str)
{
  auto it2 =  std::find_if( str.begin() , str.end() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( str.begin() , it2);
  return str;
}

std::string & rtrim(std::string & str)
{
  auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( it1.base() , str.end() );
  return str;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int q;

    cin >> n;
    cin >> q;

    unordered_map<string, string> tagmap;
    vector<string> current_tag;
    for (int i=-1; i<n; ++i) {
        string line;
        getline(cin, line);
        if (i == -1) { continue; }

        if (line[1] == '/') {
           current_tag.pop_back();
           continue;
        }

        auto pos = line.find(' ');
        if (pos != string::npos) {
            auto raw_tag = line.substr(1, pos);
           auto trimmed_tag = ltrim(rtrim(raw_tag));
           current_tag.push_back(trimmed_tag);
           size_t pos_start = pos+1;
           size_t pos_end;
           while ((pos_end = line.find('=', pos_start)) != string::npos) {
               string k = line.substr(pos_start, pos_end-pos_start);
               k = ltrim(rtrim(k));

               auto val_start = line.find('"', pos_end+1);
               auto val_end = line.find('"', val_start+1);
               auto v = line.substr(val_start+1, val_end-val_start-1);

               string t = accumulate(begin(current_tag), end(current_tag), string(),
                                [](string &ss, string &s)
                                {
                                    return ss.empty() ? s : ss + "." + s;
                                });

                string mapkey = t + '~' + k;
                tagmap[mapkey] = v;

               pos_start = val_end+1;
           }
        } else {
            auto raw_tag = line.substr(1, line.size()-2);
           auto trimmed_tag = ltrim(rtrim(raw_tag));
           current_tag.push_back(trimmed_tag);
        }

    }
     for (int i=0; i<q; ++i) {
         string line;
         getline(cin, line);

         auto v = tagmap.find(line);
         if (v == tagmap.end()) {
             cout << "Not Found!\n";
         } else {
            cout << tagmap[line] << "\n";
         }
     }

    return 0;
}
