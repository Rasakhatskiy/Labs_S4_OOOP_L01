#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LabsS3OOOPL02Tests
{
	TEST_CLASS(LabsS3OOOPL02Tests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1, L"Assert 1");
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(1, 2, L"Assert 1");
		}
	};
}
