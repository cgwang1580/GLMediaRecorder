//
// Created by wcg3031 on 2020/7/30.
//

#pragma once

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
#include <GLES3/gl3ext.h>
#include <MyImageInfo.h>
#include "ShaderHelper.h"

#define GL_VBO_MAX	5

class EglHelper
{
public:
	// 单例
	static EglHelper* CreateInstance ();
	int Init(int usage = 0, ANativeWindow *const pWindow = nullptr); // usage: 0 for render, 1 for encode
	int UnInit ();
	int Draw ();
	bool SwapBuffers();
	void SetPresentationTime(long nsecs);
	int SetRecordWindow (ANativeWindow * const pWindow);
	int SetImageData (const int imgWidth, const int imgHeight, const unsigned char* pImgData);

private:
	EglHelper ();
	~EglHelper ();
	int CreateEGLEnv (int usage, ANativeWindow *const pWindow);
	int DestroyEGLEnv ();

	int createShader();
	void destroyShader();
	int creteGLBuffer ();
	void destroyGLBuffer ();
	int drawFBO ();

	static EglHelper *m_EGLHelper;
	EGLDisplay m_EGLDisplay;
	EGLConfig m_EGLConfig;
	EGLSurface m_EGLSurface;
	EGLContext m_EGLContext;
	bool m_bEGLEnvReady;
	ANativeWindow *m_pRecordWindow;
	PFNEGLPRESENTATIONTIMEANDROIDPROC m_pPresentTimeFunc;

	GLuint m_VAO;
	GLuint m_VBO;
	//GLuint m_VBO[GL_VBO_MAX];
	GLuint m_EBO;
	GLuint m_FBO;
	GLuint m_FBOTexture;
	ShaderHelper* m_pShaderHelperNormal;
	ShaderHelper* m_pShaderHelperFBO;

	long m_lBeginTime;

	int m_ImgWidth;
	int m_ImgHeight;
	int m_ImgFormat;
	MyImageInfo m_RenderImg;

	int m_FrameID;
};



