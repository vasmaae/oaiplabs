#include "images.h"

void image0(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[4] = {
        cx,         cy,
        cx + 40,    cy,
        cx + 20,    cy + 40,
        cx,         cy
    };
    Polyline(hdc, p, 4);
    DeleteObject(hPen);
}

void image1(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[4] = {
        cx,         cy + 40,
        cx + 20,    cy,
        cx + 40,    cy + 40,
        cx,         cy + 40
    };
    Polyline(hdc, p, 4);
    DeleteObject(hPen);
}

void image2(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[5] = {
        cx,         cy + 20,
        cx + 20,    cy,
        cx + 40,    cy + 20,
        cx + 20,    cy + 40,
        cx,         cy + 20
    };
    Polyline(hdc, p, 5);
    DeleteObject(hPen);
}

void image3(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[5] = {
        cx,         cy,
        cx + 20,    cy + 20,
        cx + 40,    cy,
        cx + 20,    cy + 40,
        cx,         cy
    };
    Polyline(hdc, p, 5);
    DeleteObject(hPen);
}

void image4(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[6] = {
        cx,         cy + 40,
        cx,         cy,
        cx + 40,    cy,
        cx + 20,    cy + 10,
        cx + 40,    cy + 20,
        cx,         cy + 20
    };
    Polyline(hdc, p, 6);
    DeleteObject(hPen);
}

void image5(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[6] = {
        cx,         cy,
        cx + 20,    cy + 20,
        cx + 40,    cy,
        cx + 40,    cy + 40,
        cx,         cy + 40,
        cx,         cy
    };
    Polyline(hdc, p, 6);
    DeleteObject(hPen);
}

void image6(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[13] = {
        cx + 20,    cy,
        cx,         cy + 20,
        cx,         cy + 40,
        cx + 20,    cy + 40,
        cx + 40,    cy + 20,
        cx + 40,    cy,
        cx + 30,    cy,
        cx + 10,    cy + 20,
        cx + 10,    cy + 30,
        cx + 20,    cy + 30,
        cx + 30,    cy + 20,
        cx + 30,    cy + 10,
        cx + 20,    cy + 20
    };
    Polyline(hdc, p, 13);
    DeleteObject(hPen);
}