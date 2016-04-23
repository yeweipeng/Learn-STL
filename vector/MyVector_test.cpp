#include "gtest/gtest.h"
#include "MyVector.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int size = 7;
MyVector<string> myvec(size);
vector<string> vec(size);

MyVector<int> myempty_vec;
vector<int> empty_vec;

TEST(vector, size) {
	ASSERT_EQ(myvec.size(), vec.size());
	ASSERT_EQ(myvec.max_size(), vec.max_size());
	ASSERT_EQ(myvec.empty(), vec.empty());

	ASSERT_EQ(myempty_vec.size(), empty_vec.size());
	ASSERT_EQ(myempty_vec.max_size(), empty_vec.max_size());
	ASSERT_EQ(myempty_vec.empty(), empty_vec.empty());

	ASSERT_EQ(myvec.capacity(), vec.capacity());
}

TEST(vector, access) {
	ASSERT_EQ(myvec[0], vec[0]);
	myvec[0] = "abc";
	vec[0] = "abc";
	ASSERT_EQ(myvec[0], vec[0]);  // 引用
//	ASSERT_EQ(myvec.at(myvec.size()), vec.at(0)); // 测试异常

	ASSERT_EQ(myvec.front(), vec.front());
	ASSERT_EQ(myvec.back(), vec.back());
}

TEST(vector, modify) {
	myvec.push_back("New");
	vec.push_back("New");

	myvec.pop_back();
	vec.pop_back();

	myvec.clear();
	vec.clear();
	ASSERT_EQ(vec.back(), myvec.back());
	ASSERT_EQ(vec.capacity(), myvec.capacity());
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

