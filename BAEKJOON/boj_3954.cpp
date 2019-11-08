#include <iostream>
#include <stack>
#include <string>
using namespace std;

int tc, mem_size, code_size, input_size;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> tc;

	for (int tes = 1; tes <= tc; tes++) {
		int mem_[100000] = {};
		int max_op_idx = 0;
		int Count = 0;
		char arr_op[4096];
		int arr_input[4096] = { 0, };
		int input_idx = 0, mem_idx = 0, idx = 0;
		string str;
		stack<int> st;
		int trans_[4096] = { 0, };

		cin >> mem_size >> code_size >> input_size;

		for (int i = 0; i < code_size; i++) {
			cin >> arr_op[i];
			if (arr_op[i] == '[') st.push(i);
			else if (arr_op[i] == ']') {
				trans_[st.top()] = i;
				trans_[i] = st.top();
				st.pop();
			}
		}

		cin >> str;
		for (int i = 0; i < (int)str.size(); i++) arr_input[i] = (int)str[i];

		while (true) {
			//printf("cur : %d, idx : %d, cnt : %d\n", cur, idx, cnt);
			if (arr_op[idx] == '-') {
				mem_[mem_idx] == 0 ? mem_[mem_idx] = 255 : mem_[mem_idx]--;
			}
			else if (arr_op[idx] == '+') {
				mem_[mem_idx] == 255 ? mem_[mem_idx] = 0 : mem_[mem_idx]++;
			}
			else if (arr_op[idx] == '<') {
				mem_idx == 0 ? mem_idx = mem_size - 1 : mem_idx--;
			}
			else if (arr_op[idx] == '>') {
				mem_idx == mem_size - 1 ? mem_idx = 0 : mem_idx++;
			}
			else if (arr_op[idx] == ',') {
				input_idx == input_size ? mem_[mem_idx] = 255 : mem_[mem_idx] = arr_input[input_idx++];
			}
			else if (arr_op[idx] == '[') {
				if (mem_[mem_idx] == 0) {
					Count++; idx = trans_[idx]; continue;
				}
				//loop_i1 = idx; loop_i2 = trans[idx]; loop_val = mem_[cur];
				
			}
			else if (arr_op[idx] == ']') {
				if (mem_[mem_idx] != 0) {
					Count++; idx = trans_[idx]; continue;
				}
				//loop_i1 = trans[idx]; loop_i2 = idx; loop_val = mem_[cur];
			}

			idx++; Count++;
			if (idx > max_op_idx) {
				max_op_idx = idx;
			}

			if (idx == code_size) {
				printf("Terminates\n"); break;
			}

			if (Count > 50000000) {
				printf("Loops %d %d\n", trans_[max_op_idx], max_op_idx); break;
			}
		}

	}
	
	return 0;
}