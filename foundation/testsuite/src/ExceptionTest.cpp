#include <gtest/gtest.h>

#include "orca/Exception.h"

TEST(ExceptionTest, MessagesTest) {
    std::string expectedMessage = "Expected Message";
    const char* expectedFileName = "Expected FileName";
    const char* expectedFunctionName = "Expected FunctionName";
    int expectedLine = 1;
    const char* expectedWhat = "[message]: Expected Message; [file]: Expected FileName; [function]: Expected FunctionName; [line]: 1;";
    
    std::string actualMessage; 
    std::string actualFileName; 
    std::string actualFunctionName; 
    int actualLine;
    std::string actualWhat;

    try {
        throw orca::Exception(expectedMessage, expectedFileName, 
            expectedFunctionName, expectedLine);
    }
    catch (const orca::Exception & e) {
        actualMessage = e.message();
        actualFileName = e.fileName();
        actualFunctionName = e.functionName();
        actualLine = e.line();
        actualWhat = e.what();
    }
    EXPECT_EQ(expectedMessage, actualMessage);
    EXPECT_EQ(expectedFileName, actualFileName);
    EXPECT_EQ(expectedFunctionName, actualFunctionName);
    EXPECT_EQ(expectedLine, actualLine);
    EXPECT_EQ(expectedWhat, actualWhat);
}

TEST(ExceptionTest, ThrowMacroTest) {
    std::string expectedMessage = "Expected Message";
    std::string actualMessage;
    try {
        ORCA_THROW_EXCEPTION(expectedMessage);
    }
    catch (const orca::Exception & e) {
        actualMessage = e.message();
    }
    EXPECT_EQ(expectedMessage, actualMessage);
}

TEST(ExceptionTest, RequireMacroTest_FALSE) {
    std::string expectedMessage = "Expected Message";
    std::string actualMessage;
    try {
        ORCA_REQUIRE(false, expectedMessage);
    }
    catch (const orca::Exception & e) {
        actualMessage = e.message();
    }
    EXPECT_EQ(expectedMessage, actualMessage);
}

TEST(ExceptionTest, RequireMacroTest_TRUE) {
    std::string unexpectedMessage = "UnExpected Message";
    std::string actualMessage = "";
    try {
        ORCA_REQUIRE(true, unexpectedMessage);
    }
    catch (const orca::Exception & e) {
        actualMessage = e.message();
    }
    EXPECT_EQ("", actualMessage);
}
