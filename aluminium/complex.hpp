#ifndef ALUMINIUM_COMPLEX
#define ALUMINIUM_COMPLEX

#include <cmath>

namespace aluminium {
namespace complex {


class complex_ {
  private:
    long double m_r;   // real
    long double m_i;   // imaginary
    long double m_abs; // absolute
    long double m_arg; // argument

    long double absolute(const long double &r, const long double &i) {
        if (r == 0)
            return i;
        if (i == 0)
            return r;
        return sqrt(r * r + i * i);
    }

    long double argument(const long double &r, const long double &i) {
        long double ret {0};
        const long double pi {3.14159265358979323846L};
        if (r == 0 && i == 0) return 0;
        ret = atan2(i, r);
        if (i < 0) ret += 2 * pi;
        return ret;
    }

  public:
    // constructor
    complex_() {
        m_r = 0;
        m_i = 0;
        m_abs = 0;
        m_arg = 0;
    }

    complex_(const complex_ &x) {
        m_r = x.r();
        m_i = x.i();
        m_abs = x.abs();
        m_arg = x.arg();
    }

    complex_(const long double &r, const long double &i) {
        m_r = r;
        m_i = i;
        compute();
    }

    // operator
    complex_ &operator=(const complex_ &x) {
        m_r = x.r();
        m_i = x.i();
        m_abs = x.abs();
        m_arg = x.arg();
        return *this;
    }

    complex_ operator+(const complex_ &x) {
        complex_ ret;
        ret.r(m_r + x.r());
        ret.i(m_i + x.i());
        return ret;
    }

    complex_ &operator+=(const complex_ &x) {
        *this = *this + x;
        return *this;
    }

    complex_ operator-(const complex_ &x) {
        complex_ ret;
        ret.r(m_r - x.r());
        ret.i(m_i - x.i());
        return ret;
    }

    complex_ &operator-=(const complex_ &x) {
        *this = *this - x;
        return *this;
    }

    complex_ operator*(const complex_ &x) {
        complex_ ret;
        ret.r(m_r * x.r() - m_i * x.i());
        ret.i(m_r * x.i() + m_i * x.r());
        return ret;
    }

    complex_ &operator*=(const complex_ &x) {
        *this = *this * x;
        return *this;
    }

    complex_ operator/(const complex_ &x) {
        complex_ ret;
        ret = *this * x.conjugate();
        ret.abs(ret.abs() / (x.abs() * x.abs()));
        return ret;
    }

    complex_ &operator/=(const complex_ &x) {
        *this = *this / x;
        return *this;
    }

    // funcs
    constexpr long double r() const {
        return m_r;
    }
    long double r(const long double &x) {
        m_r = x;
        compute();
        return m_r;
    }

    constexpr long double i() const {
        return m_i;
    }
    long double i(const long double &x) {
        m_i = x;
        compute();
        return m_i;
    }

    constexpr long double abs() const {
        return m_abs;
    }
    long double abs(const long double &x) {
        m_r *= (x / m_abs);
        m_i *= (x / m_abs);
        m_abs = x;
        return m_abs;
    }

    constexpr long double arg() const {
        return m_arg;
    }
    long double arg(const long double &x) {
        m_arg = x;
        m_r = m_abs * cos(m_arg);
        m_i = m_abs * sin(m_arg);
        return m_arg;
    }

    const complex_ conjugate() const {
        complex_ ret(m_r, m_i * -1);
        return ret;
    }

    void compute() {
        m_abs = absolute(m_r, m_i);
        m_arg = argument(m_r, m_i);
    }
};

} // namespace complex
} // namespace aluminium

#endif
