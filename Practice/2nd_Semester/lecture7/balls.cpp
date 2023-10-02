#include "balls.h"
#include <QPainter>
#include <QPoint>
Balls::Balls() {}

int Balls::x() const { // const - значит метод константный, т.е. он ничего не поменяет в полях класса
    return m_x;
}

int Balls::y() const {
    return m_y;
}

int Balls::r() const {
    return m_r;
}

int Balls::dx() const {
    return m_dx;
}

int Balls::dy() const {
    return m_dy;
}

void Balls::setX(int x) {
    m_x = x;
}

void Balls::setY(int y) {
    m_y = y;
}

void Balls::setR(int r) {
    m_r = r;
}

void Balls::setDX(int dx) {
    m_dx = dx;
}

void Balls::setDY(int dy) {
    m_dy = dy;
}

void Balls::draw(QPainter *painter) // перенесли метод отрисовки сюда
{
    painter->drawEllipse(QPoint(m_x, m_y), m_r, m_r); // т.к. painter передаём по указателю, то пишем ->()
}

void Balls::move(int w, int h)
{
    if ((m_x - m_r <= 0)||(m_x + m_r >= w)) // отражаем от левой или правой стенки
        m_dx = -m_dx;

    if ((m_y - m_r <= 0)||(m_y + m_r >= h)) // отражаем от верхней или нижней стенки
        m_dy = -m_dy;

    m_x += m_dx, m_y += m_dy;
}
