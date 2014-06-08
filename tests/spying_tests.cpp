/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */

#include "tpunit++.hpp"
#include "fakeit.hpp"

using namespace fakeit;

struct SpyingTests: tpunit::TestFixture {

	SpyingTests() :
			tpunit::TestFixture( //
					TEST(SpyingTests::test1), TEST(SpyingTests::test2)) {
	}

	struct SomeClass {
		virtual int func(int arg) {
			return arg;
		}
		virtual int func2(int arg) {
			return ++arg;
		}
	};

	void test1() {
		SomeClass obj;
		Mock<SomeClass> s(obj);
		Fake(s[&SomeClass::func]);
		SomeClass& i = s.get();
		ASSERT_EQUAL(0, i.func(1));
		ASSERT_EQUAL(1, i.func2(0));
		Verify(s[&SomeClass::func](1));
//		Spy(s[&SomeClass::func]);
//
//		VirtualTable<SomeClass>* clone = VirtualTable<SomeClass>::cloneVTable(obj);
//		clone->apply(obj);
//		auto a = obj.func(1);
//		auto a2 = obj.func2(1);
//		a++;//
	}

	void test2() {
	}
//
} __SpyingTests;

