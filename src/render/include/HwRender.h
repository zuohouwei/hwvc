/*
 * Copyright (c) 2018-present, lmyooyo@gmail.com.
 *
 * This source code is licensed under the GPL license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef HARDWAREVIDEOCODEC_RENDER_H
#define HARDWAREVIDEOCODEC_RENDER_H

#include "Unit.h"
#include "Filter.h"
#include "HwBuffer.h"

class HwRender : public Unit {
public:
    HwRender(string alias);

    virtual ~HwRender();

    bool eventRelease(Message *msg) override;

    bool eventPrepare(Message *msg);

    bool eventRenderFilter(Message *msg);

    bool eventSetFilter(Message *msg);

    bool eventReadPixels(Message *msg);

private:
    void checkFilter(int width, int height);

    void renderFilter(GLuint texture);

    void renderScreen();

    void setFilterParams(int *params);

    void notifyPixelsReady();

private:
    Filter *filter = nullptr;
    Filter *yuvReadFilter = nullptr;
    uint8_t *pixels = nullptr;
    int count = 0;
    HwBuffer *buf = nullptr;
    int64_t tsInNs = 0;
};


#endif //HARDWAREVIDEOCODEC_RENDER_H
