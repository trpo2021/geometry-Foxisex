#include <ctest.h>
#include <libgeometry/geometry.h>

CTEST(collisions, HaveCollisions)
{
    int num_of_circles = 2;
    struct circle circles[num_of_circles];
    int collisions[num_of_circles][num_of_circles];

    circles[0].x = 0;
    circles[0].y = 0;
    circles[0].radius = 2;
    circles[1].x = 2;
    circles[1].y = 0;
    circles[1].radius = 5;

    checkforcollisions(circles, num_of_circles, collisions);

    ASSERT_EQUAL(0, collisions[0][0]);
    ASSERT_EQUAL(1, collisions[0][1]);
    ASSERT_EQUAL(1, collisions[1][0]);
    ASSERT_EQUAL(0, collisions[1][1]);
}

CTEST(collisions, HaveNoCollisions)
{
    int num_of_circles = 2;
    struct circle circles[num_of_circles];
    int collisions[num_of_circles][num_of_circles];

    circles[0].x = 10;
    circles[0].y = 0;
    circles[0].radius = 2;
    circles[1].x = 2;
    circles[1].y = 0;
    circles[1].radius = 5;

    checkforcollisions(circles, num_of_circles, collisions);

    ASSERT_EQUAL(0, collisions[0][0]);
    ASSERT_EQUAL(0, collisions[0][1]);
    ASSERT_EQUAL(0, collisions[1][0]);
    ASSERT_EQUAL(0, collisions[1][1]);
}

CTEST(P_and_S, perimetr)
{
    struct circle* c = malloc(sizeof(struct circle));
    c->radius = 6.9;

    float real = circle_p(c);
    float exp = 43.353981;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(P_and_S, square)
{
    struct circle* c = malloc(sizeof(struct circle));
    c->radius = 6.9;

    float real = circle_s(c);
    float exp = 149.571228;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(get_prmtr, rightgetting)
{
    char cx[15] = "";
    char str[40] = {"circle (12.3234 2, 2)"};
    int i = 8;

    float real = get_prmtr(str, i, cx);
    float exp = 12.323400;

    ASSERT_DBL_NEAR(exp, real);
}

CTEST(checkcircle, NoErrors)
{
    char str[40] = {"circle (12.3234 2.32, 2.521)"};
    int cur_circle = 0;
    struct circle circles[1];

    int real = checkcircle(str, circles, cur_circle);
    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(checkcircle, IncorrectCircle)
{
    char str[40] = {"circcle (12.3234 2.32, 2.521)"};
    int cur_circle = 0;
    struct circle circles[1];

    int real = checkcircle(str, circles, cur_circle);
    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(checkcircle, NoOpenBracket)
{
    char str[40] = {"circle 12.3234 2.32, 2.521)"};
    int cur_circle = 0;
    struct circle circles[1];

    int real = checkcircle(str, circles, cur_circle);
    int exp = 2;

    ASSERT_EQUAL(exp, real);
}

CTEST(checkcircle, NoSpaceAfterFirstCoord)
{
    char str[40] = {"circle (12.32342.32, 2.521)"};
    int cur_circle = 0;
    struct circle circles[1];

    int real = checkcircle(str, circles, cur_circle);
    int exp = 3;

    ASSERT_EQUAL(exp, real);
}

CTEST(checkcircle, NoSpaceOrCommaAfterSecondCoord)
{
    char str[40] = {"circle (12.3234 2.322.521)"};
    int cur_circle = 0;
    struct circle circles[1];

    int real = checkcircle(str, circles, cur_circle);
    int exp = 4;

    ASSERT_EQUAL(exp, real);
}

CTEST(checkcircle, NoCommaAfterSecondCoord)
{
    char str[40] = {"circle (12.3234 2.32 2.521)"};
    int cur_circle = 0;
    struct circle circles[1];

    int real = checkcircle(str, circles, cur_circle);
    int exp = 5;

    ASSERT_EQUAL(exp, real);
}

CTEST(checkcircle, NoSpaceOrCloseBracketAfterRadius)
{
    char str[40] = {"circle (12.3234 2.32, 2.521"};
    int cur_circle = 0;
    struct circle circles[1];

    int real = checkcircle(str, circles, cur_circle);
    int exp = 6;

    ASSERT_EQUAL(exp, real);
}

CTEST(checkcircle, NoCloseBracketAfterRadius)
{
    char str[40] = {"circle (12.3234 2.32, 2.521 ("};
    int cur_circle = 0;
    struct circle circles[1];

    int real = checkcircle(str, circles, cur_circle);
    int exp = 7;

    ASSERT_EQUAL(exp, real);
}
