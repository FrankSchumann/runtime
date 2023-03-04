#include <gtest/gtest.h>

#include "factory/RuntimeControllerFactory.h"

TEST( RuntimeControllerFactoryTest, Failed )
{
    GTEST_FAIL();
}

TEST( RuntimeControllerFactoryTest, create )
{
    RuntimeControllerFactory runtimeControllerFactory;

    std::string const name = std::string( "Daisy Duck" );
    auto const runtimeController = runtimeControllerFactory.create( name );

    ASSERT_NE( nullptr, runtimeController );

    ASSERT_EQ( name, runtimeController->getName() );
    ASSERT_EQ( std::string( "RuntimeController" ), runtimeController->getType() );
}

TEST( RuntimeControllerFactoryTest, getType )
{
    RuntimeControllerFactory runtimeControllerFactory;

    std::string const type = runtimeControllerFactory.getType();

    EXPECT_EQ( "RuntimeController", type );
}
