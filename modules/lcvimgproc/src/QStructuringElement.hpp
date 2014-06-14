#ifndef QSTRUCTURINGELEMENT_HPP
#define QSTRUCTURINGELEMENT_HPP

#include <QQuickItem>
#include "QMat.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class QStructuringElement : public QQuickItem{

    Q_OBJECT
    Q_PROPERTY(ElementShape shape  READ shape  WRITE setShape  NOTIFY shapeChanged)
    Q_PROPERTY(QSize        ksize  READ ksize  WRITE setKsize  NOTIFY ksizeChanged)
    Q_PROPERTY(QPoint       anchor READ anchor WRITE setAnchor NOTIFY anchorChanged)
    Q_PROPERTY(QMat*        output READ output WRITE setOutput NOTIFY outputChanged)

    Q_ENUMS(ElementShape)

    enum ElementShape{
        MORPH_RECT    = cv::MORPH_RECT,
        MORPH_ELLIPSE = cv::MORPH_ELLIPSE,
        MORPH_CROSS   = cv::MORPH_CROSS
    };

public:
    QStructuringElement(QQuickItem* parent = 0);
    ~QStructuringElement();

    int shape() const;
    void setShape(int shape);

    const QSize& ksize() const;
    void setKsize(const QSize& ksize);

    const QPoint& anchor() const;
    void setAnchor(const QPoint& anchor);

    QMat* output() const;
    void setoutput(QMat* output);

    void setOutputDirty();

signals:
    void ksizeChanged();
    void shapeChanged();
    void anchorChanged();
    void outputChanged();

private:
    ElementShape m_shape;
    QPoint       m_anchor;
    QSize        m_ksize;
    QMat*        m_output;
    bool         m_outputDirty;
};

inline void QStructuringElement::setOutputDirty(){
    m_outputDirty = true;
    emit outputChanged();
}

inline void QStructuringElement::setOutput(QMat*output){
	if (m_output != output){
        m_output = output;
		emit outputChanged();
	}
}

inline const QPoint& QStructuringElement::anchor() const{
	return m_anchor;
}

inline void QStructuringElement::setAnchor(const QPoint& anchor){
	if (m_anchor != anchor){
		m_anchor = anchor;
        emit anchorChanged();
	}
}

inline const QSize& QStructuringElement::ksize() const{
    return m_ksize;
}

inline void QStructuringElement::setKsize(const QSize& ksize){
    if (m_ksize != ksize){
        m_ksize = ksize;
        emit ksizeChanged();
	}
}

inline int QStructuringElement::shape() const{
	return m_shape;
}

inline void QStructuringElement::setShape(intshape){
	if (m_shape != shape){
		m_shape = shape;
		emit shapeChanged();
	}
}


#endif // QSTRUCTURINGELEMENT_HPP
