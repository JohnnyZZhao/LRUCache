#include "LRUCache.h"
#include <gtest/gtest.h>


class LRUCacheTestFixture : public testing::Test
{
    
};

TEST_F(LRUCacheTestFixture, GivenEmptyCacheWithSizeOne_Get_ReturnMinusOne)
{
    LRUCache cache(1);
    EXPECT_EQ(-1, cache.get(1));
}

TEST_F(LRUCacheTestFixture, GivenCacheWithSizeTwo_SetAndGet_ReturnValues)
{
    LRUCache cache(2);
    cache.set(1, 1);
    cache.set(2, 2);

    EXPECT_EQ(1, cache.get(1));
    EXPECT_EQ(2, cache.get(2));

    cache.set(1, 3);

    EXPECT_EQ(3, cache.get(1));
}

TEST_F(LRUCacheTestFixture, GivenCacheWithSizeTwo_Overflow_GetOldKeyReturnsMinusOne)
{
    LRUCache cache(2);
    cache.set(1, 1);
    cache.set(2, 2);
    cache.set(3, 3);

    EXPECT_EQ(-1, cache.get(1));
    EXPECT_EQ(2, cache.get(2));
    EXPECT_EQ(3, cache.get(3));

    cache.set(1, 1);
    cache.set(4, 4);

    EXPECT_EQ(1, cache.get(1));
    EXPECT_EQ(4, cache.get(4));
    EXPECT_EQ(-1, cache.get(2));
    EXPECT_EQ(-1, cache.get(3));
}