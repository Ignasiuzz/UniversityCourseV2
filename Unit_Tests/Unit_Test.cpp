#include <gtest/gtest.h>
#include "../Studentas.h"
#include "../VectorIncludes.h"

TEST(Unit_Tests, Default_Constructor) {
    Studentas s1;

    EXPECT_EQ(s1.Vardas(), "");
    EXPECT_EQ(s1.Pavarde(), "");
    std::vector<double> expected_values = {};
    EXPECT_EQ(s1.Namudarbas(), expected_values);
    EXPECT_EQ(s1.Egzaminas(), 0);
}

TEST(Unit_Tests2, Stringstream_Constructor) {
    istringstream iss("John Doe 1 1 1 1 1");
    Studentas s2;
    s2.readStudent(iss);

    EXPECT_EQ(s2.Vardas(), "John");
    EXPECT_EQ(s2.Pavarde(), "Doe");
    std::vector<double> expected_values = {1, 1, 1, 1};
    EXPECT_EQ(s2.Namudarbas(), expected_values);
    EXPECT_EQ(s2.Egzaminas(), 1);
}

TEST(Unit_Tests3, Copy_Constructor) {
    Studentas s3("John", "Doe", 2, {2, 2, 2, 2});
    Studentas s4=s3;

    EXPECT_EQ(s4.Vardas(), "John");
    EXPECT_EQ(s4.Pavarde(), "Doe");
    std::vector<double> expected_values = {2, 2, 2, 2};
    EXPECT_EQ(s4.Namudarbas(), expected_values);
    EXPECT_EQ(s4.Egzaminas(), 2);
}