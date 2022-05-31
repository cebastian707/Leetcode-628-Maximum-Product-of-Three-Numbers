/*By::Cebastian Santiago
* Leetcode 628
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

bool allnegative(std::vector<int> temp) {
	int count = 0;

	for (size_t i = 0; i < temp.size(); i++) {
		if (temp[i] <= 0) {
			count++;
		}

	}

	if (count == temp.size()){
		return true;
	}

	return false;
}




bool allpostive(std::vector<int> nums) {
	int count = 0;
	
	for (size_t i = 0; i < nums.size(); i++){
		if (nums[i] >= 0) {
			count++;
		}

	}

	if (count == nums.size()){
		return true;
	}

	return false;
}



int maximumProduct(std::vector<int>& nums) {
	//creat min heap
	std::priority_queue<int, std::vector<int>, std::greater<int>> min;
	//sort the vector
	std::sort(nums.begin(), nums.end());
	
	//get the size of the vector
	int temp = nums.size();
	int max = 1;
	//subtracte three to temp
	int tres = temp - 3;

	//1.if all the numbers are postive 
	if (allpostive(nums)){
		//know loop through the vector
		for (size_t i = 0; i < nums.size(); i++) {
			//once were at the last three elements
			//start mutpliying
			if (i >= tres) {
				max *= nums[i];
			}
		}
		return max;
	}

	//2.if the vector is all negative numbers
	else if (allnegative(nums)) {
		for (size_t i = 0; i < nums.size(); i++){
			if (i >= tres){
				max *= nums[i];
			}
		}

		return max;
	}

	//3.if we have negatives in the vector with postive numbers
	else  {
		//inser elements into the heap
		for (size_t i = 0; i < nums.size(); i++){
			min.push(nums[i]);
		}

		//pop the first two elements of the min heap
		int minf = min.top();
		min.pop();
		int mins = min.top();
		min.pop();
		int size = nums.size() - 1;
		int answer = minf * mins * nums[size];
		
		//compare the last three postie numbers with the negative ones
		for (size_t i = 0; i < nums.size(); i++){
			if (i >= tres){
				max *= nums[i];
			}
		}

		max = std::max(answer, max);
		return max;

	}

	return  max;
}



int main(int argv, char* argc[]) {
	std::vector<int> nums = {-710,-107,-851,657,-14,-859,278,-182,-749,718,-640,127,-930,-462,694,969,143,309,904,-651,160,451,-159,-316,844,-60,611,-169,-73,721,-902,338,-20,-890,-819,-644,107,404,150,-219,459,-324,-385,-118,-307,993,202,-147,62,-94,-976,-329,689,870,532,-686,371,-850,-186,87,878,989,-822,-350,-948,-412,161,-88,-509,836,-207,-60,771,516,-287,-366,-512,509,904,-459,683,-563,-766,-837,-333,93,893,303,908,532,-206,990,280,826,-13,115,-732,525,-939,-787 };

	std::cout << maximumProduct(nums) << std::endl;

	return 0;
}
