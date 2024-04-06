from django.shortcuts import render
from django.http import HttpResponse


def app2_func2(request):
    return HttpResponse('you are at app2')
# Create your views here.
