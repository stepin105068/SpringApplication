package com.studentapp.exception;

import java.time.LocalDateTime;
import java.util.Arrays;
import java.util.List;

import org.springframework.beans.TypeMismatchException;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.HttpMediaTypeNotSupportedException;
import org.springframework.web.HttpRequestMethodNotSupportedException;
import org.springframework.web.bind.MissingPathVariableException;
import org.springframework.web.bind.MissingServletRequestParameterException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.context.request.WebRequest;
import org.springframework.web.servlet.mvc.method.annotation.ResponseEntityExceptionHandler;



public class GlobalExceptionHandler extends ResponseEntityExceptionHandler {
	
	@Override
    protected ResponseEntity<Object> handleHttpRequestMethodNotSupported(HttpRequestMethodNotSupportedException ex,
            HttpHeaders headers, HttpStatus status, WebRequest request) {
        String message=  ex.getMessage();
        LocalDateTime timeStamp  = LocalDateTime.now();
        List<String> details = 
                Arrays.asList("Wrong method name","Not supported");
        APIErrors errors = 
          new APIErrors(message, timeStamp, status, details);
        return ResponseEntity.status(status).body(errors);
    }

 

    @Override
    protected ResponseEntity<Object> handleHttpMediaTypeNotSupported(HttpMediaTypeNotSupportedException ex,
            HttpHeaders headers, HttpStatus status, WebRequest request) {
        String message=  ex.getMessage();
        LocalDateTime timeStamp  = LocalDateTime.now();
        List<String> details = 
                Arrays.asList("Wrong Media type ","Irrelevant");
        APIErrors errors = 
          new APIErrors(message, timeStamp, status, details);
        return ResponseEntity.status(status).body(errors);
    }

 

    @Override
    protected ResponseEntity<Object> handleMissingPathVariable(MissingPathVariableException ex, HttpHeaders headers,
            HttpStatus status, WebRequest request) {
        String message=  ex.getMessage();
        LocalDateTime timeStamp  = LocalDateTime.now();
        List<String> details = 
                Arrays.asList("Misssing Path Variable","No variable");
        APIErrors errors = 
          new APIErrors(message, timeStamp, status, details);
        return ResponseEntity.status(status).body(errors);
    }

 

    @Override
    protected ResponseEntity<Object> handleMissingServletRequestParameter(MissingServletRequestParameterException ex,
            HttpHeaders headers, HttpStatus status, WebRequest request) {
        String message=  ex.getMessage();
        LocalDateTime timeStamp  = LocalDateTime.now();
        List<String> details = 
                Arrays.asList("No Request Param","missing param");
        APIErrors errors = 
          new APIErrors(message, timeStamp, status, details);
        return ResponseEntity.status(status).body(errors);
    }

 

    @Override
    protected ResponseEntity<Object> handleTypeMismatch(TypeMismatchException ex, HttpHeaders headers,
            HttpStatus status, WebRequest request) {
        String message=  ex.getMessage();
        LocalDateTime timeStamp  = LocalDateTime.now();
        List<String> details = 
                Arrays.asList("Mismatch of data types","Wrong type");
        APIErrors errors = 
          new APIErrors(message, timeStamp, status, details);
        return ResponseEntity.status(status).body(errors);
        
    }

 

    @ExceptionHandler(StudentNotFoundException.class)
    public ResponseEntity<Object> 
               handleBookException(StudentNotFoundException ex){
        String message=  ex.getMessage();
        LocalDateTime timeStamp  = LocalDateTime.now();
        List<String> details = 
                Arrays.asList("Book is not available");
        APIErrors errors = 
          new APIErrors(message, timeStamp, HttpStatus.BAD_REQUEST, details);
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(errors);
    }
    @ExceptionHandler(Exception.class)
    public ResponseEntity<Object> 
               handleOtherException(Exception ex){
        String message=  ex.getMessage();
        LocalDateTime timeStamp  = LocalDateTime.now();
        List<String> details = 
                Arrays.asList(message);
        APIErrors errors = 
          new APIErrors(message, timeStamp, HttpStatus.INTERNAL_SERVER_ERROR, details);
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(errors);
    }

}
