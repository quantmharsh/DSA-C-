SET SERVEROUTPUT ON; 
CREATE OR REPLACE PROCEDURE add_customer ( p_cus_code IN INT, p_cus_fname IN VARCHAR2, p_cus_lname IN VARCHAR2, p_cus_balance IN NUMBER 
) 
IS 
BEGIN 
INSERT INTO customer (cus_code, cus_fname, cus_lname, cus_balance) VALUES (p_cus_code, p_cus_fname, p_cus_lname, p_cus_balance); END; 
/ 
 BEGIN 
add_customer (&cus_code, '&cus_fname', '&cus_lname', '&cus_balance'); END; 
/ 
 
SELECT * FROM customer; 
SELECT COUNT(*) FROM customer WHERE customer.cus_code = 1002; 

SET SERVEROUTPUT ON; 
CREATE OR REPLACE PROCEDURE add_invoicee( p_inv_no IN INT, p_cus_code IN INT, p_inv_date IN date, p_inv_amount IN number 
) 
AS 
BEGIN 
INSERT INTO invoicee (inv_no, cus_code, inv_date, inv_amount) 


VALUES (p_inv_no, p_cus_code, p_inv_date, p_inv_amount); END; 
/ 
 BEGIN 
add_invoicee (&inv_no, &cus_code, '&inv_date', '&inv_amount'); END; 
/ 
 
SELECT * FROM invoicee; 
 
SELECT COUNT(*) FROM invoicee WHERE 
invoicee.inv_no = 8006;  

CREATE OR REPLACE FUNCTION get_invoice_total(p_inv_no IN invoicee.inv_no%TYPE) 
RETURN INT AS 
l_total INT; 
BEGIN 
SELECT inv_amount 
INTO l_total 
FROM line 
WHERE inv_no = p_inv_no; 
RETURN l_total; 
END; 
/ 
 
CREATE OR REPLACE FUNCTION get_customer_total(p_cus_code IN customer.cus_code%TYPE) 
RETURN INT AS 
l_total INT; 
BEGIN 
SELECT SUM(get_invoice_total(inv_no)) 
INTO l_total 
FROM invoicee 
WHERE cus_code = p_cus_code; 
RETURN l_total; 
END; 
/ 
 DECLARE l_total INT; BEGIN 
l_total := get_customer_total(1000); 
DBMS_OUTPUT.PUT_LINE('Total purchase: ' || l_total); 
END; 
 
/ 
 
 











 




BEGIN 
add_invoicee(8005, 1000, '30-MAY-16', 307.72); 
END; 
/ 
CREATE OR REPLACE PROCEDURE delete_invoicee(p_inv_no IN invoicee.inv_no%TYPE) 
AS 
BEGIN 
DELETE FROM line WHERE inv_no = p_inv_no; 
DELETE FROM invoice WHERE inv_no = p_inv_no; 
END; 
/ BEGIN 
delete_invoicee(8005); delete_invoicee(8006); 
END; 
/ 



CREATE OR REPLACE PROCEDURE display_invoice_totals(p_inv_no IN invoicee.inv_noTYPE) AS 
l_subtotal NUMBER; l_tax NUMBER; l_total NUMBER; 
BEGIN 
SELECT SUM(Line_ units * Line_price) 
INTO l_subtotal 
FROM line 
WHERE inv_no = p_inv_no; l_tax := l_subtotal * 0.08; l_total := l_subtotal + l_tax; 
DBMS_OUTPUT.PUT_LINE('INV_SUBTOTAL: ' || l_subtotal); 
DBMS_OUTPUT.PUT_LINE('INV_TAX: ' || l_tax); 
DBMS_OUTPUT.PUT_LINE('INV_TOTAL: ' || l_total); 
END; 
/ 


DECLARE 
CURSOR c_vendors IS 
SELECT V_name 
FROM productt p INNER JOIN vendor v ON p.v_code = v.v_code 
WHERE p.P_qoh <= p.P_min; 
BEGIN 
FOR r IN c_vendors 
LOOP 
DBMS_OUTPUT.PUT_LINE('Vendor: ' || r.V_name); 
END LOOP; END; 

CREATE OR REPLACE TRIGGER new_customer_balance 
AFTER INSERT ON invoicee 
FOR EACH ROW 
BEGIN 
UPDATE customer 
SET cus_balance = cus_balance + :new.inv_amount 
WHERE cus_code = :new.cus_code; 
END; 
/ 
 
INSERT INTO invoicee (inv_no, cus_code, inv_date, inv_amount) VALUES 
(8005, 1001, '27-APR-16', '225.40'); select * from invoicee where inv_no=8005; 


CREATE OR REPLACE TRIGGER update_balance_on_delete 
AFTER DELETE ON invoicee 
FOR EACH ROW 
BEGIN 
UPDATE customer 
SET cus_balance = cus_balance - :old.inv_amount 
WHERE cus_code = :old.cus_code; 
END; 
/ 


CREATE OR REPLACE TRIGGER update_product_qoh AFTER INSERT ON line 
FOR EACH ROW 
BEGIN 
UPDATE productt 
SET p_qoh = p_qoh - :new.line_units 
WHERE p_code = :new.p_code; 
END; 
/ 
 

CREATE OR REPLACE TRIGGER check_customer_balance 
BEFORE INSERT ON invoicee 
FOR EACH ROW DECLARE 
l_balance NUMBER; 
BEGIN 
SELECT cus_balance 
INTO l_balance 
FROM customer 
WHERE cus_code = :new.cus_code; 
IF l_balance < :new.inv_amount THEN 
RAISE_APPLICATION_ERROR(-20000, 'Invoice amount exceeds customer balance');  
END IF; 
END; 
/ 

