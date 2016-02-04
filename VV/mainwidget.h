
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "geometryengine.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QPushButton>

class GeometryEngine;

class MainWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    void rotateBy(int xAngle, int yAngle, int zAngle);
    ~MainWidget();

protected:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *e) Q_DECL_OVERRIDE;
    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void initShaders();
    void initTextures();

signals:
    void clicked();

//private slots:
    //void handleButton();

private:
    QBasicTimer timer;
    QOpenGLShaderProgram program;
    GeometryEngine *geometries;
    QOpenGLTexture *texture;
    QMatrix4x4 projection;
    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    qreal angularSpeed;
    QQuaternion rotation;
    QPushButton *m_button;
    QPoint lastPos;
    int xRot;
    int yRot;
    int zRot;
    float passIt;
};

#endif // MAINWIDGET_H