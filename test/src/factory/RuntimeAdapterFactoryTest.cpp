#include <gtest/gtest.h>

#include "factory/RuntimeAdapterFactory.h"

TEST( RuntimeAdapterFactoryTest, Failed )
{
    GTEST_FAIL();
}

TEST( RuntimeAdapterFactoryTest, create )
{
	RuntimeAdapterFactory runtimeAdapterFactory;

    std::string const name = std::string( "Daisy Duck" );
    auto runtimeAdapter = runtimeAdapterFactory.create( name );

    ASSERT_NE( nullptr, runtimeAdapter );

    ASSERT_EQ( name, runtimeAdapter->getName() );
    ASSERT_EQ( std::string( "RuntimeAdapter" ), runtimeAdapter->getType() );

}

TEST( RuntimeAdapterFactoryTest, getType )
{
    RuntimeAdapterFactory runtimeAdapterFactory;

    std::string const type = runtimeAdapterFactory.getType();

    EXPECT_EQ( "RuntimeAdapter", type );
}
