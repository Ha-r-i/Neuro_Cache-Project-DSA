#ifndef UTILS_H
#define UTILS_H

inline float normalize(int value, int maxVal) {
    return maxVal == 0 ? 0.0f : (float)value / maxVal;
}

#endif  