#ifndef MUSICIMAGEUTILS_H
#define MUSICIMAGEUTILS_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2021 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include "musicglobaldefine.h"

/*! @brief The namespace of the utils widget.
 * @author Greedysky <greedysky@163.com>
 */
namespace MusicUtils
{
    namespace Image
    {
        /*!
         * Set pixmap to round by ratio.
         */
        TTK_MODULE_EXPORT QPixmap pixmapToRound(const QPixmap &input, int ratioX, int ratioY);
        /*!
         * Set pixmap to round by ratio.
         */
        TTK_MODULE_EXPORT QPixmap pixmapToRound(const QPixmap &input, const QSize &size, int ratioX, int ratioY);
        /*!
         * Set pixmap to round by ratio.
         */
        TTK_MODULE_EXPORT QPixmap pixmapToRound(const QPixmap &input, const QRect &rect, int ratioX, int ratioY);
        /*!
         * Set pixmap to round by ratio.
         */
        TTK_MODULE_EXPORT QPixmap pixmapToRound(const QPixmap &input, const QPixmap &mask, const QSize &size);
        /*!
         * Get bitmap mask from rect.
         */
        TTK_MODULE_EXPORT QBitmap getBitmapMask(const QRect &rect, int ratioX, int ratioY);

        /*!
         * Get pximap data.
         */
        TTK_MODULE_EXPORT QByteArray getPixmapData(const QPixmap &input);

        /*!
         * Set fusion two pixmap.
         */
        TTK_MODULE_EXPORT void fusionPixmap(QPixmap &back, const QPixmap &front, const QPoint &pt);
        /*!
         * Set fusion two image.
         */
        TTK_MODULE_EXPORT void fusionPixmap(QImage &back, const QImage &front, const QPoint &pt);

        /*!
         * Image gray scale.
         */
        TTK_MODULE_EXPORT QPixmap grayScalePixmap(const QPixmap &input, int radius = 0);
        /*!
         * Image gray average.
         */
        TTK_MODULE_EXPORT int grayScaleAverage(const QImage &input, int width, int height);

        /*!
         * Rerender the custum value.
         */
        template <typename T>
        TTK_MODULE_EXPORT T reRenderValue(const T &key, const T &alpha, const T &value)
        {
            if(alpha < 0) return 0;
            else if(alpha > key) return key;

            return (key - alpha) * 1.0 / 100 * value + alpha;
        }

        /*!
         * Rerender the image alpha.
         */
        TTK_MODULE_EXPORT int reRenderAlpha(int alpha, int value);
        /*!
         * Rerender the image by color burn transform.
         */
        TTK_MODULE_EXPORT void reRenderImage(int delta, const QImage *input, QImage *output);
        /*!
         * Image color burn transform.
         */
        TTK_MODULE_EXPORT int colorBurnTransform(int c, int delta);

    }
}

#endif // MUSICIMAGEUTILS_H
