class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> words;
        int begin = 0, forward = 0;
        while (forward < paragraph.size()) {
            while (forward < paragraph.size() && (
					paragraph[forward] == '!' || 
					paragraph[forward] == '?' ||
					paragraph[forward] == ',' ||
					paragraph[forward] == '\'' ||
					paragraph[forward] == ';' ||
					paragraph[forward] == '.' ||
					paragraph[forward] == ' '))
				++forward;
			begin = forward;
			while (forward < paragraph.size() && !(
					paragraph[forward] == '!' || 
					paragraph[forward] == '?' ||
					paragraph[forward] == ',' ||
					paragraph[forward] == '\'' ||
					paragraph[forward] == ';' ||
					paragraph[forward] == '.' ||
					paragraph[forward] == ' '))
				++forward;
			if (begin != forward) {
				string tmp = paragraph.substr(begin, forward - begin);
				for (auto &i : tmp) if (i >= 'A' && i <= 'Z') i = i - 'A' + 'a';
				bool flag = true;
				for (auto b : banned)
					if (b == tmp) {
						flag = false;
						break;
					}
				begin = ++forward;
				if (!flag) continue;
				auto f = words.find(tmp);
				if (f == words.end()) words[tmp] = 1;
				else ++words[tmp];
			}
        }
		int maxCnt = -1;
		string res;
		for (auto i = words.begin(); i != words.end(); ++i) {
            cout << i->second << " " << i->first << endl;
			if (i->second > maxCnt) {
				maxCnt = i->second;
				res = i->first;
			}
		}
		return res;
    }
};